import urllib.parse
import json
from json import JSONDecodeError
from os import listdir, getcwd
from os.path import isdir, exists

PATH = getcwd()

extensions = {
    "c++": ".cpp",
    "python": ".py",
    "java": ".java",
    "javascript": ".js",
    "bash": ".sh",
    "mysql": ".sql"
}

__MAIN_README_HEADER__ = """# Leetcode-solutions
Solutions to over than 1800 Leetcode problems in four programming languages (C++, Python, Java, and Javascript).
# How did I do it ? #
  - For detailed description of the problem check out my other repository [Leetcode-scraper](https://github.com/AnasImloul/Leetcode-solutions/) where I published the source code and documentation for the project.
# Solutions"""

__TOPIC_README_HEADER__ = """# ?-solutions
This folder contains Solutions to % ? Leetcode problems written in the following programming languages (§).<br><br>
Access solutions by alphabetical order:
"""

__ALPHABETICAL_README_HEADER__ = """# ?-solutions
This folder contains Solutions to % ? Leetcode problems that starts with '$' written in the following programming languages (§).<br><br>
### Problems ###"""

SOLUTIONS_TABLE_COLUMNS = ["problem", "languages", "difficulty", "Leetcode"]
SOLUTIONS_TABLE_ALIGNS = ["left", "center", "center", "center"]

TOPICS = ("algorithms", "database", "shell", "concurrency")

CLASSES = ["0-9", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
           "T", "U", "V", "W", "X", "Y", "Z"]

ALPHABETICAL_ORDER_CLASSES_COLUMNS = ["  " + _class + "  " for _class in CLASSES]

ALPHABETICAL_ORDER_CLASSES_ALIGNS = ["center"] * len(ALPHABETICAL_ORDER_CLASSES_COLUMNS)


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


def get_all_file_extensions_from_path(path, recursion_limit=10):
    sub_dirs = get_all_subdirectories(path)

    extension_set = set()
    if recursion_limit == 0 or sub_dirs == []:
        for file in listdir(path):
            if not isdir(path + "\\" + file):
                extension_set.add("." + file.split(".")[-1] if "." in file else "")

    else:
        for sub_dir in sub_dirs:
            extension_set = {*extension_set, *get_all_file_extensions_from_path(path + "\\" + sub_dir)}
    return extension_set


def format_problem_to_table_row(info, _class):
    problem_name = info.get("name", "")
    problem_url = info.get("url", "")
    difficulty = info.get("difficulty", "")
    languages = sorted(info.get("solution", dict()).keys())
    topic = info.get("topic", "")

    if problem_name == "":
        return ""

    scripts_link = "https://github.com/AnasImloul/Leetcode-solutions/tree/main/"

    problem_github_link = scripts_link + topic + "/" + _class + "/" + urlencode(problem_name) + "/"

    # https://github.com/AnasImloul/Leetcode-solutions/blob/main/scripts/algorithms/All%20O%60one%20Data%20Structure/All%20O%60one%20Data%20Structure.java

    languages_md = ", ".join(
        map(lambda
                lang: f"[{lang.capitalize()}]({problem_github_link + urlencode(problem_name) + extensions[lang.lower()]})",
            languages))

    return f"|[{problem_name}]({problem_github_link})|{languages_md}|{difficulty.capitalize()}|[link]({problem_url})|"


def generate_alphabetical_order_link_table(topic):
    topic_path = "\\".join((PATH, topic))

    table = "\n" + table_columns_header(
        [(
            f"[{_class}](https://github.com/AnasImloul/Leetcode-solutions/tree/main/{topic}/{_class}/#{topic}-solutions)" if len(
                get_all_subdirectories(
                    topic_path + "\\" + _class)) > 0 else f"<span style='color:grey'>  {_class} </span>")
            for _class in CLASSES[:len(CLASSES) // 2 + 2]],
        ["center"] * (len(CLASSES) // 2 + 2))

    table += "\n" + table_columns_header(
        [(
            f"**[{_class}](https://github.com/AnasImloul/Leetcode-solutions/tree/main/{topic}/{_class}/#{topic}-solutions)**" if len(
                get_all_subdirectories(
                    topic_path + "\\" + _class)) > 0 else f"**<span style='color:grey'>  {_class}  </span>**")
            for _class in CLASSES[len(CLASSES) // 2:]],
        ["center"] * (1 + len(CLASSES) // 2)).split("\n")[0]

    return table


def get_total_problem_folders(topic):
    topic_path = "\\".join((PATH, topic))
    return sum(len(get_all_subdirectories(topic_path + "\\" + _class)) for _class in get_all_subdirectories(topic_path))


def get_all_script_languages(topic):
    topic_path = "\\".join((PATH, topic))
    all_languages = set({ext: lang for lang, ext in extensions.items()}.get(extension, "").capitalize() for extension in
                        get_all_file_extensions_from_path(topic_path))
    all_languages.remove('')
    return all_languages


def generate_topic_readme_file(topic_path):
    topic = topic_path.split("\\")[-1]

    readme = __TOPIC_README_HEADER__.replace("?", topic.capitalize()) \
        .replace("%", str(get_total_problem_folders(topic))) \
        .replace("§", " " + ", ".join(get_all_script_languages(topic)) + " ")

    readme += generate_alphabetical_order_link_table(topic)

    return readme


def generate_problems_table(topic, _class):
    table = "\n" + table_columns_header(["problems", "langages", "difficulty", "Leetcode"],
                                        ["left", "center", "center", "center"])

    class_path = "\\".join((PATH, topic, _class))

    for problem in get_all_subdirectories(class_path):
        info = load_json(class_path + "\\" + problem + "\\" + "info.json")
        table += "\n" + format_problem_to_table_row(info, _class)

    return table


def generate_alphabetical_readme_file(class_path):
    all_languages = set({ext: lang for lang, ext in extensions.items()}.get(extension, "").capitalize() for extension in
                        get_all_file_extensions_from_path(class_path))
    all_languages.remove('')

    topic, _class = class_path.split("\\")[-2:]

    readme = __ALPHABETICAL_README_HEADER__.replace("?", topic.capitalize()) \
        .replace("%", str(len(get_all_subdirectories(class_path)))) \
        .replace("$", _class) \
        .replace("§", " " + " ,".join(all_languages) + " ")

    readme += generate_problems_table(topic, _class)

    return readme


def generate_main_readme_file(scripts_path):
    readme = __MAIN_README_HEADER__

    all_dirs = get_all_subdirectories(scripts_path)

    for topic in TOPICS:
        if topic in all_dirs:
            readme += "\n" + f"### [{topic.capitalize()}](https://github.com/AnasImloul/Leetcode-solutions/tree/main/{topic}/#{topic}-solutions) ###"
            readme += "\n" + f"Check out solutions to {get_total_problem_folders(topic)}" \
                             f"problems from the {topic.capitalize()} category written in " \
                             f"( {', '.join(get_all_script_languages(topic))}) . "
            readme += "\n" + generate_alphabetical_order_link_table(topic)
    return readme


def update_main_readme_file():
    readme_path = PATH + "\\README.md"
    scripts_path = PATH
    with open(readme_path, encoding="utf-8", mode="w") as readme:
        readme.write(generate_main_readme_file(scripts_path))


def update_topic_readme_file(topic):
    readme_path = PATH + "\\" + topic + "\\README.md"
    topic_path = PATH + "\\" + topic
    with open(readme_path, encoding="utf-8", mode="w") as readme:
        readme.write(generate_topic_readme_file(topic_path))


def update_alphabetical_readme_file(topic, _class):
    readme_path = "\\".join((PATH, topic, _class, "README.md"))
    class_path = "\\".join((PATH, topic, _class))

    if len(get_all_subdirectories(class_path)) == 0:
        return

    with open(readme_path, encoding="utf-8", mode="w") as readme:
        readme.write(generate_alphabetical_readme_file(class_path))


if __name__ == "__main__":

    update_main_readme_file()

    for topic in TOPICS:
        update_topic_readme_file(topic)

        for _class in get_all_subdirectories("\\".join((PATH, topic))):
            update_alphabetical_readme_file(topic, _class)
