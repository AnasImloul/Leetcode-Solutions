from scraper.file_utils import load_json, get_all_subdirectories
from scraper.web_utils import urlencode
from scraper.code_utils import extension



__README_HEADER__ = """# Leetcode-solutions
Solutions to over than 1800 Leetcode problems in four programming languages (C++, Python, Java, and Javascript).
## Scraping the solutions ##
+ ### extracting the problemset ###
  - Check out this Python script [./scraper/problemset/scrap.py](https://github.com/AnasImloul/Leetcode-solutions/tree/main/scraper/problemset/scrap.py) to see how we extracted the problemset from the Leetcode website.
  
+ ### extracting the scripts ###
  - Check out this Python script [./scraper/solutions/scrap.py](https://github.com/AnasImloul/Leetcode-solutions/tree/main/scraper/solutions/scrap.py) to see how we extracted the solutions from the Leetcode discuss section.

# Solutions"""

__README_TABLES_COLUMNS__ = """| problem  |  languages   | difficulty | Leetcode |
|:---------|:------------:|:----------:|:--------:|"""


def format_problem_to_table_row(info):
    problem_name = info.get("name", "")
    problem_url = info.get("url", "")
    difficulty = info.get("difficulty","")
    languages = sorted(info.get("solution", dict()).keys())
    topic = info.get("topic", "")
    if problem_name == "":
        return ""

    scripts_link = "https://github.com/AnasImloul/Leetcode-solutions/tree/main/scripts/"

    problem_github_link = scripts_link + topic + "/" + urlencode(problem_name) + "/"

    # https://github.com/AnasImloul/Leetcode-solutions/blob/main/scripts/algorithms/All%20O%60one%20Data%20Structure/All%20O%60one%20Data%20Structure.java

    languages_md = ", ".join(
        map(lambda lang: f"[{lang.capitalize()}]({problem_github_link + urlencode(problem_name) + extension(lang)})",
            languages))

    return f"|[{problem_name}]({problem_github_link})|{languages_md}|{difficulty.capitalize()}|[link](https://leetcode.com/_next/static/images/logo-dark-c96c407d175e36c81e236fcfdd682a0b.png)|"


def generate_readme_file(readme_path, scripts_path):
    readme = __README_HEADER__

    for topic in get_all_subdirectories(scripts_path):


        scripts_link = "https://github.com/AnasImloul/Leetcode-solutions/tree/main/scripts/"
        topic_github_link = scripts_link + topic

        readme += "\n" + f" + ## [{topic.capitalize()}]({topic_github_link}) ##"
        readme += "\n" + __README_TABLES_COLUMNS__

        for problem_folder in get_all_subdirectories(scripts_path + "\\" + topic):
            try:
                info = load_json(scripts_path + "\\" + topic + "\\" + problem_folder + "\\info.json")
            except:
                continue

            problem_row = format_problem_to_table_row(info)

            if problem_row == "":
                continue

            readme += "\n" + problem_row

    return readme


def update_readme_file(readme_path, scripts_path):
    with open(readme_path ,mode="w") as readme:
        readme.write(generate_readme_file(readme_path, scripts_path))


update_readme_file(readme_path=r"C:\Users\hp\Desktop\Projects\Leetcode-solutions\README.md",
                                         scripts_path=r"C:\Users\hp\Desktop\Projects\Leetcode-solutions\scripts")
