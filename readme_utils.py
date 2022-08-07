import urllib.parse
import json
from json import JSONDecodeError
from os import listdir
from os.path import isdir, exists


def load_json(file):
    if not exists(file):
        with open(file, mode="w") as f:
            pass

    with open(file, mode="r") as f:
        try:
            data = json.loads(f.read())
        except JSONDecodeError:
            data = dict()
    return data


def get_all_subdirectories(path):
    return list(filter(lambda sub_path: isdir(path + "\\" + sub_path), listdir(path)))


def urlencode(string):
    return urllib.parse.quote(string)


extensions = {
    "c++":".cpp",
    "python":".py",
    "java":".java",
    "javascript":".js"
}


__README_HEADER__ = """# Leetcode-solutions
Solutions to over than 1800 Leetcode problems in four programming languages (C++, Python, Java, and Javascript).
# How did I do it ? #
  - For detailed description of the problem check out my other repository [Leetcode-scraper](https://github.com/AnasImloul/Leetcode-solutions/) where I published the source code and documentation for the project.
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
        map(lambda lang: f"[{lang.capitalize()}]({problem_github_link + urlencode(problem_name) + extensions[lang.lower()]})",
            languages))

    return f"|[{problem_name}]({problem_github_link})|{languages_md}|{difficulty.capitalize()}|[link]({problem_url})|"


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
