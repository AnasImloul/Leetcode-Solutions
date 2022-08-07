import scraper.web_utils as web
import scraper.file_utils as file

__PROBLEM_SET_URL__ = "http://www.leetcode.com/problemset/"
__PROBLEM_SET_CONTAINER_XPATH__ = '//*[@id="__next"]/div/div/div[1]/div[1]/div[6]/div[2]'

__PROBLEM_SET_XPATH__ = '//*[@id="__next"]/div/div/div[1]/div[1]/div[6]/div[2]/div/div/div[2]'
__PROBLEM_SET_NEXT_PAGE_XPATH__ = '//*[@id="__next"]/div/div/div[1]/div[1]/div[6]/div[3]/nav'

__PROBLEM_NAME_RELATIVE_XPATH__ = '/div[2]/div/div/div/div/a'
__PROBLEM_DIFFICULTY_RELATIVE_XPATH__ = '/div[5]/span'
__PROBLEM_PREMIUM_LOCK_XPATH__ = '/div[2]/div/div/div'


def access_problem_set_page_by_topic(browser, topic):
    web.access_url_page(browser, url=__PROBLEM_SET_URL__ + topic, title="Problems - LeetCode")


def extract_problem_name(browser, xpath):
    name_element = web.get_element_by_xpath(browser, xpath + "/" + __PROBLEM_NAME_RELATIVE_XPATH__)
    name = "".join(filter(lambda char: char not in "0123456789.", web.get_innerHTML(name_element))).strip()
    return name


def extract_problem_url(browser, xpath):
    url_element = web.get_element_by_xpath(browser, xpath + "/" + __PROBLEM_NAME_RELATIVE_XPATH__)
    return web.get_href(url_element)


def extract_problem_premium(browser, xpath):
    premium_lock = web.get_element_by_xpath(browser, xpath + "/" + __PROBLEM_PREMIUM_LOCK_XPATH__)
    premium_lock = web.children_count(premium_lock)
    return premium_lock == 2


def extract_problem_difficulty(browser, xpath):
    difficulty_element = web.get_element_by_xpath(browser, xpath + "/" + __PROBLEM_DIFFICULTY_RELATIVE_XPATH__)
    return web.get_innerHTML(difficulty_element).lower()


def extract_problem_info(browser, problem_xpath):
    problem_name = problem_url = problem_difficulty = problem_premium = ""

    for iteration in range(3):
        try:
            problem_name = extract_problem_name(browser, problem_xpath)
            problem_url = extract_problem_url(browser, problem_xpath)
            problem_difficulty = extract_problem_difficulty(browser, problem_xpath)
            problem_premium = extract_problem_premium(browser, problem_xpath)
            break
        except:
            continue
    return {"name": problem_name, 'url': problem_url, 'difficulty': problem_difficulty, 'premium': problem_premium}


def wait_until_container_load(container):
    return web.wait_until_element_attribute(element=container,
                                            attribute="class",
                                            value="-mx-4 md:mx-0",
                                            timeout=60)


def get_all_problems_from_page(browser, *, easy=True, medium=True, hard=True, premium=False, topic="algorithms"):
    difficulties = {"easy": easy, "medium": medium, "hard": hard}

    container = web.wait_until_element_load_by_xpath(browser, __PROBLEM_SET_CONTAINER_XPATH__)
    if not wait_until_container_load(container):
        return dict()

    problem_rows = web.wait_until_element_load_by_xpath(browser, __PROBLEM_SET_XPATH__)
    if problem_rows is None:
        return dict()

    all_problems = dict()

    number_of_problems = web.children_count(problem_rows)
    for problem_index in range(number_of_problems):
        problem_xpath = __PROBLEM_SET_XPATH__ + f"/div[{problem_index + 1}]"

        problem_info = extract_problem_info(browser, problem_xpath)

        if premium or not problem_info['premium']:
            if difficulties[problem_info['difficulty']]:
                all_problems[problem_info['name']] = {**problem_info, **{'topic': topic}}

    return all_problems


def access_next_problem_set_page(browser):
    buttons = web.wait_until_element_load_by_xpath(browser, __PROBLEM_SET_NEXT_PAGE_XPATH__)
    count = web.children_count(buttons)

    button_xpath = f"{__PROBLEM_SET_NEXT_PAGE_XPATH__}/button[{count}]"
    next_page = web.get_element_by_xpath(browser, button_xpath)
    if not next_page.is_enabled():
        return False
    web.click_button(browser, next_page)
    return True


def fetch_by_topic(browser, *, save_path=None, easy=True, medium=True, hard=True, premium=True, topic="algorithms"):
    all_problems = dict()

    access_problem_set_page_by_topic(browser, topic)


    while True:
        new_problems = get_all_problems_from_page(browser, easy=easy, medium=medium, hard=hard, premium=premium,
                                                  topic=topic)

        all_problems = {**all_problems, **new_problems}

        if save_path is not None:
            data = file.load_json(save_path)
            for problem, info in new_problems.items():
                data[problem] = info
            file.save_json(save_path, data)

        if not access_next_problem_set_page(browser):
            break

    return all_problems


def fetch(browser, *, save_path=None, easy=True, medium=True, hard=True, premium=True, algorithms=True, database=False,
          shell=False, concurrency=False):
    all_problems = dict()

    if algorithms:
        all_problems = {**all_problems,
                        **fetch_by_topic(browser,
                                         save_path=save_path,
                                         easy=easy,
                                         medium=medium,
                                         hard=hard,
                                         premium=premium,
                                         topic="algorithms"
                                         )
                        }

    if database:
        all_problems = {**all_problems,
                        **fetch_by_topic(browser,
                                         save_path=save_path,
                                         easy=easy,
                                         medium=medium,
                                         hard=hard,
                                         premium=premium,
                                         topic="database"
                                         )
                        }

    if shell:
        all_problems = {**all_problems,
                        **fetch_by_topic(browser,
                                         save_path=save_path,
                                         easy=easy,
                                         medium=medium,
                                         hard=hard,
                                         premium=premium,
                                         topic="shell"
                                         )
                        }

    if concurrency:
        all_problems = {**all_problems,
                        **fetch_by_topic(browser,
                                         save_path=save_path,
                                         easy=easy,
                                         medium=medium,
                                         hard=hard,
                                         premium=premium,
                                         topic="concurrency"
                                         )
                        }

    return all_problems