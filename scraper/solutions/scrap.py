import scraper.web_utils as web
import scraper.code_utils as code
import scraper.file_utils as file
from selenium.webdriver import ActionChains
from selenium.webdriver.common.keys import Keys
import threading

MUTEX_LOCK = threading.Lock()

language_slider = {"c++" : 0, "java" : 1, "python3" : 3, "javascript" : 6}

extension = {"c++": ".cpp", "python": ".py", "python3": ".py", "java": ".java", "javascript": ".js"}


PROBLEM_DISCUSS_TAG_INPUT_XPATH = '//*[@id="discuss-container"]/div/div/div[2]/div/div[2]/span[1]/span[1]/input'
PROBLEM_DISCUSS_SEARCH_TAGS_LIST_XPATH = '//*[@id="discuss-container"]/div/div/div[2]/div/div[2]/div'
PROBLEM_DISCUSS_LOADING_STATE_XPATH = '//*[@id="discuss-container"]/div/div/div[1]/div/div[3]/div/div[1]'
PROBLEM_DISCUSS_POSTS_LIST_XPATH = '//*[@id="discuss-container"]/div/div/div[1]/div/div[3]/div/div[2]'
PROBLEM_DISCUSS_POST_CONTENT_XPATH = '//*[@id="discuss-container"]/div/div/div[2]/div[1]/div[2]/div[2]/div'
PROBLEM_DISCUSS_POST_NAME_RELATIVE_XPATH = "/div/div[1]/div[1]/a"

PROBLEM_SUBMISSION_CODE_XPATH = '//*[@id="app"]/div/div[2]/div[1]/div/div[3]/div/div[1]/div/div[2]/div/div/div[6]'
PROBLEM_SUBMISSION_LANGUAGE_SLIDER_XPATH = '//*[@id="app"]/div/div[2]/div[1]/div/div[3]/div/div[1]/div/div[1]/div[1]/div/div/div'
PROBLEM_SUBMISSION_LANGUAGE_LIST_XPATH = '/html/body/div[7]/div/div/div/ul'


def access_problem_page(browser, problem_name, problem_url):
    web.access_url_page(browser, url=problem_url, title=problem_name)


def get_submission_template(browser, language):
    language = language if language != "python" else "python3"

    if language not in language_slider:
        return None

    for iteration in range(3):
        try:
            slider = web.wait_until_element_load_by_xpath(browser, PROBLEM_SUBMISSION_LANGUAGE_SLIDER_XPATH)
            web.click_button(browser, slider)

            languages_list = web.get_children(
                web.wait_until_element_visible_by_xpath(browser, PROBLEM_SUBMISSION_LANGUAGE_LIST_XPATH))

            selected_language = languages_list[language_slider[language]]

            web.click_button(browser, selected_language)

            submission_area = web.wait_until_element_visible_by_xpath(browser, PROBLEM_SUBMISSION_CODE_XPATH)

            web.click_button(browser, submission_area)
            ActionChains(browser).key_down(Keys.CONTROL).send_keys('a').key_up(Keys.CONTROL).perform()
            ActionChains(browser).key_down(Keys.CONTROL).send_keys('c').key_up(Keys.CONTROL).perform()
            break
        except:
            continue
    template = web.get_from_clipboard()
    template = "\n".join(
        filter(lambda line: not line.lstrip().startswith("#") or line.lstrip().startswith("//"), template.splitlines()))
    return template


def get_submission_template_multiple_languages(browser, languages):
    return {language : get_submission_template(browser, language) for language in languages}


def access_discuss_page(browser, problem_name, problem_url):
    if problem_url.endswith("/"):
        discuss = "discuss/"
    else:
        discuss = "/discuss/"

    web.access_url_page(browser,url= problem_url + discuss, title=problem_name)


def filter_discuss_posts_by_tag(browser, tag):
    for iteration in range(3):
        try:
            loading = web.wait_until_element_load_by_xpath(browser, PROBLEM_DISCUSS_LOADING_STATE_XPATH)
            search_tag = web.wait_until_element_load_by_xpath(browser, PROBLEM_DISCUSS_TAG_INPUT_XPATH)
            web.fill_text_input(search_tag, tag)
            tag_list = web.wait_until_element_load_by_xpath(browser, PROBLEM_DISCUSS_SEARCH_TAGS_LIST_XPATH)
            tag = web.get_children(tag_list)[0]
            web.click_button(browser, tag)
            web.wait_until_element_attribute(loading, "data-status", "exited")
            break
        except:
            continue


def access_discuss_post_by_rank(browser, rank=1):
    try:
        post_xpath = PROBLEM_DISCUSS_POSTS_LIST_XPATH + f"/div[{rank + 1}]" + PROBLEM_DISCUSS_POST_NAME_RELATIVE_XPATH
        post_name = web.wait_until_element_load_by_xpath(browser, post_xpath, timeout=10)
        url = web.get_href(post_name)
        web.access_url_page(browser, url)
    except:
        return False
    return True


def valid_submission(script, template, language):

    script = code.remove_comments(script, language)
    template = code.remove_comments(template, language)
    if language != "python":

        script = script.replace("{", "").replace("}", "").replace(";", "")
        template = template.replace("{", "").replace("}", "").replace(";", "")

        script_lines = code.get_non_empty_lines(script)
        template_lines = code.get_non_empty_lines(template)

        return all(template_line in script_lines for template_line in template_lines)

    else:
        classes = code.get_classes_name(script)
        functions = code.get_functions_name(script)

        template_classes = code.get_classes_name(template)
        template_functions = code.get_functions_name(template)

        return all(template_class in classes for template_class in template_classes) and all(template_function in functions for template_function in template_functions)


def get_valid_script_from_post(browser, template, language):
    post_container = web.wait_until_element_visible_by_xpath(browser, PROBLEM_DISCUSS_POST_CONTENT_XPATH)

    try:
        content_html = web.get_outerHTML(post_container)
    except:
        return None

    all_scripts = code.extract_scripts(content_html)

    for script in all_scripts:
        script = code.extract_clean_code(script)
        if valid_submission(script, template, language):
            return script
    return None


def get_valid_script_from_post_multiple_languages(browser, templates):
    return {language : get_valid_script_from_post(browser, template, language) for language, template in templates.items()}


def fetch_valid_solution(browser, problem, languages, max_posts=10):
    access_problem_page(browser, problem_name=problem['name'], problem_url=problem['url'])

    templates = get_submission_template_multiple_languages(browser, languages)
    scripts = {language : None for language in languages}

    for language in languages:
        access_discuss_page(browser, problem_name=problem['name'], problem_url=problem['url'])
        filter_discuss_posts_by_tag(browser, language)

        rank = 0
        while rank <= max_posts:

            if not access_discuss_post_by_rank(browser, rank):
                break

            new_scripts = get_valid_script_from_post_multiple_languages(browser, templates)

            for _language in scripts:
                if scripts[_language] is None:
                    scripts[_language] = new_scripts[_language]

            if scripts[language] is None:
                max_posts -= 1
                rank += 1
                web.return_to_previous_page(browser)
                continue
            else:
                break
    return scripts


def fetch(browser, save_path, problems, languages):
    languages = list(map(lambda language:language.lower(), languages))
    languages.sort(key=lambda language:language_slider.get(language, 0))

    solutions = dict()

    for name, problem in problems.items():
        valid_name = file.clean_file_name(name)
        problem_folder = save_path + "\\" + problem['topic'] + "\\" + valid_name


        file.create_directory(problem_folder)

        info = file.load_json(problem_folder + "\\" + "info.json")

        if info == dict():
            info = {**problem, **{"solution": {language: False for language in languages}}}


        _languages = list(filter(lambda lang : not info.get("solution", dict()).get(lang, False), languages))
        if not _languages:
            continue

        solution = fetch_valid_solution(browser, problem, _languages)
        solutions[problem['name']] = solution

        for language, script in solution.items():
            if script is None:
                continue
            save_solution(problem_folder, valid_name, script, language)
            info["solution"][language] = True
        print(info["solution"])
        file.save_json(problem_folder + "\\" + "info.json", info)
    return solutions


def save_solution(save_path, name, solution, language):
    with open(save_path + "\\" + name + extension.get(language, ".txt"), encoding="utf-8", mode="w") as f:
        f.write(solution)