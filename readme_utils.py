import encodings
import urllib.parse
import json
from json import JSONDecodeError
from os import listdir
from os.path import isdir, exists
from random import random


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


def table_columns_header(columns, aligns):
    table = ["", ""]

    for column, align in zip(columns, aligns):
        table[0] += f"|{column}"
        if align == "left":
            table[1] += "|:" + (len(column) - 1) * "-"
        elif align == "right":
            table[1] += "|" + (len(column) - 1) * "-" + ":"
        else:
            table[1] += "|:" + (len(column) - 2) * "-" + ":"

    table[0] += "|"
    table[1] += "|"

    return "\n".join(table)




extensions = {
    "c++":".cpp",
    "python":".py",
    "java":".java",
    "javascript":".js",
    "bash": ".sh",
    "mysql": ".sql"
}


__README_HEADER__ = """# Leetcode-solutions
Solutions to over than 1800 Leetcode problems in four programming languages (C++, Python, Java, and Javascript).
# How did I do it ? #
  - For detailed description of the problem check out my other repository [Leetcode-scraper](https://github.com/AnasImloul/Leetcode-solutions/) where I published the source code and documentation for the project.
# Solutions"""

SOLUTIONS_TABLE_COLUMNS = ["problem", "languages", "difficulty", "Leetcode"]
SOLUTIONS_TABLE_ALIGNS = ["left", "center", "center", "center"]


TOPICS = ("algorithms", "database", "shell", "concurrency")

CLASSES = ["0-9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
           "T", "U", "V", "W", "X", "Y", "Z"]



ALPHABETICAL_ORDER_CLASSES_COLUMNS = ["  " + _class + "  " for _class in CLASSES]

ALPHABETICAL_ORDER_CLASSES_ALIGNS = ["center"]*len(ALPHABETICAL_ORDER_CLASSES_COLUMNS)




def format_problem_to_table_row(info):
    problem_name = info.get("name", "")
    problem_url = info.get("url", "")
    difficulty = info.get("difficulty","")
    languages = sorted(info.get("solution", dict()).keys())
    topic = info.get("topic", "")
    if problem_name == "":
        return ""

    scripts_link = "https://github.com/AnasImloul/Leetcode-solutions/tree/main/"

    problem_github_link = scripts_link + topic + "/" + urlencode(problem_name) + "/"

    # https://github.com/AnasImloul/Leetcode-solutions/blob/main/scripts/algorithms/All%20O%60one%20Data%20Structure/All%20O%60one%20Data%20Structure.java

    languages_md = ", ".join(
        map(lambda lang: f"[{lang.capitalize()}]({problem_github_link + urlencode(problem_name) + extensions[lang.lower()]})",
            languages))

    return f"|[{problem_name}]({problem_github_link})|{languages_md}|{difficulty.capitalize()}|[link]({problem_url})|"



#def alphabetical_order_classes(topic):



def generate_readme_file(scripts_path):
    readme = __README_HEADER__

    readme += "\n" + table_columns_header([f"[{topic.capitalize()}](#{topic.capitalize()})" for topic in TOPICS],
                                          ["center"] * 4)

    for topic in TOPICS:


        topic_path = scripts_path + "\\" + topic

        if not exists(topic_path):
            continue

        scripts_link = "https://github.com/AnasImloul/Leetcode-solutions/tree/main/"
        topic_github_link = scripts_link + topic



        readme += "\n" + f"## [{topic.capitalize()}]({topic_github_link}) ##"

        for _class in CLASSES:
            class_path = topic_path + "\\" + _class
            if not exists(class_path) or len(get_all_subdirectories(class_path)) == 0:
                continue

            readme += "\n" + f"### {_class} ###"
            readme += "\n" + table_columns_header(SOLUTIONS_TABLE_COLUMNS, SOLUTIONS_TABLE_ALIGNS)


            for problem_folder in get_all_subdirectories(class_path):

                try:
                    info = load_json(class_path + "\\" + problem_folder + "\\info.json")
                except:
                    continue

                problem_row = format_problem_to_table_row(info)

                if problem_row == "":
                    continue

                readme += "\n" + problem_row

    return readme



def update_readme_file(readme_path, scripts_path):
    with open(readme_path , encoding="utf-8", mode="w") as readme:
        readme.write(generate_readme_file(scripts_path))


update_readme_file(readme_path=r"C:\Users\hp\Desktop\Projects\Leetcode-solutions\README.md",
                                         scripts_path=r"C:\Users\hp\Desktop\Projects\Leetcode-solutions")
