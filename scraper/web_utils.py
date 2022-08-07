from time import sleep, perf_counter
import selenium.common.exceptions
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.common.exceptions import TimeoutException
from selenium.webdriver import ActionChains
from selenium.webdriver.common.keys import Keys
import win32clipboard


__clipboard_data__ = ""


def wait_until_any_element_load_by_xpath(driver, elements_xpath, timeout=10):
    start = perf_counter()
    first_load = None
    while perf_counter() - start < timeout:
        for xpath in elements_xpath:
            try:
                first_load = get_element_by_xpath(driver, xpath)
                return xpath
            except:
                continue
        sleep(0.5)
    return first_load


def wait_until_element_attribute(element, attribute, value, timeout=10):
    start = perf_counter()
    while perf_counter() - start < timeout:
        if get_attribute(element, attribute) == value:
            return True
    return False


def wait_until_element_load_by_xpath(driver, xpath, timeout=10):
    try:
        element = WebDriverWait(driver, timeout).until(EC.presence_of_element_located((By.XPATH, xpath)))
        return element
    except TimeoutException:
        print("Loading took too much time!")
        return None


def wait_until_element_load_by_class_name(driver, class_name, timeout=10):
    try:
        element = WebDriverWait(driver, timeout).until(EC.presence_of_element_located((By.CLASS_NAME, class_name)))
        return element
    except TimeoutException:
        print("Loading took too much time!")


def wait_until_element_visible_by_xpath(driver, xpath, timeout=10):
    try:
        element = WebDriverWait(driver, timeout).until(EC.visibility_of_element_located((By.XPATH, xpath)))
        return element
    except TimeoutException:
        print("Loading took too much time!")
        return None


def wait_until_element_visible_by_class_name(driver, class_name, timeout=10):
    try:
        element = WebDriverWait(driver, timeout).until(EC.visibility_of_element_located((By.CLASS_NAME, class_name)))
        return element
    except TimeoutException:
        print("Loading took too much time!")
        return None


def get_element_by_xpath(driver, xpath):
    element = driver.find_element_by_xpath(xpath)
    return element


def get_element_by_class_name(driver, classname):
    return driver.find_element_by_class_name(classname)


def check_element_exist_by_xpath(driver, xpath):
    try:
        get_element_by_xpath(driver, xpath)
        return True

    except:
        return False


def check_element_exist_by_class_name(driver, xpath):
    try:
        get_element_by_class_name(driver, xpath)
        return True

    except:
        return False


def get_specific_child_by_xpath(element, relative_xpath):
    if relative_xpath[0] == "/":
        relative_xpath = relative_xpath[1:]
    return element.find_element_by_xpath("./" + relative_xpath)


def get_specific_child_by_class_name(element, class_name):
    return element.find_element_by_class_name(class_name)


def check_child_exist_by_xpath(element, relative_xpath):
    try:
        get_specific_child_by_xpath(element, relative_xpath)
        return True

    except:
        return False


def check_child_exist_by_class_name(element, class_name):
    try:
        get_specific_child_by_class_name(element, class_name)
        return True

    except:
        return False


def get_children(element):
    return element.find_elements_by_xpath("./*")


def children_count(element):
    return len(get_children(element))


def get_href(element):
    return element.get_attribute('href')


def get_innerHTML(element):
    return element.get_attribute('innerHTML')


def get_outerHTML(element):
    return element.get_attribute('outerHTML')


def get_attribute(element, attribute):
    return element.get_attribute(attribute)


def click_button(driver, button):
    ActionChains(driver).click(button).perform()


def fill_text_input(element, text):
    element.send_keys(text)
    element.send_keys(Keys.RETURN)


def access_url_page(driver, url, title="", timeout=30):
    refresh = True
    done = False
    start = perf_counter()
    while not done:
        while perf_counter() - start < timeout:
            try:
                if refresh:
                    driver.get(url)
                    refresh = False
                assert title in driver.title
            except selenium.common.exceptions.WebDriverException:
                sleep(1)
                refresh = True
            except AssertionError:
                sleep(1)
            finally:
                done = True
                break


def return_to_previous_page(driver):
    for iteration in range(3):
        try:
            driver.execute_script("window.history.go(-1)")
            break
        except selenium.common.exceptions.WebDriverException:
            sleep(1)


def refresh_page(driver):
    driver.refresh()


def copy_to_clipboard(text):
    win32clipboard.OpenClipboard()
    __clipboard_data__ = get_from_clipboard()
    win32clipboard.EmptyClipboard()
    win32clipboard.SetClipboardText(text)
    win32clipboard.CloseClipboard()


def get_from_clipboard():
    win32clipboard.OpenClipboard()
    data = win32clipboard.GetClipboardData()
    win32clipboard.EmptyClipboard()
    win32clipboard.SetClipboardText(__clipboard_data__)
    win32clipboard.CloseClipboard()
    return data