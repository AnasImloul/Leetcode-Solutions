import json
from json import JSONDecodeError
from os.path import exists
from os import listdir, mkdir


def save_json(file, data):
    with open(file, "w") as f:
        f.write(json.dumps(data, indent=4))


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


def file_exist(path, file):
    if path[-1] == "\\":
        path = path[-1]
    return exists(path + "\\" + file)


def path_exist(path):
    return exists(path)



def extract_scripts(text):
    scripts = []
    idx = 0
    while idx < len(text):
        try:
            start = text.index("<code>", idx)
            finish = text.index("</code>", start)
            scripts.append(text[start + 6:finish])
            idx = finish
        except:
            break
    return scripts


def clean_html_code(code, html=True):
    result = ""
    open = 0

    if html:
        for c in code:

            if c == "<":
                open += 1

            if open == 0:
                result += c

            if c == ">":
                open -= 1
    else:
        result = code

    result = result.replace("&lt;", "<")
    result = result.replace("&gt;", ">")
    result = result.replace("&amp;", "&")

    return result


def clean_file_name(file):
    file = file.replace('"', '').\
                replace('*', '').\
                replace(':', '').\
                replace('?', '').\
                replace('\\', '').\
                replace('/', '').\
                replace('|', '').\
                replace('>', '').\
                replace('<', '')
    return file


def remove_last_strings(code):
    lines = code.splitlines()
    if "```" in lines[-1]:
        return "\n".join(lines[:-1])
    return "\n".join(lines)


def file_content(file):
    with open(file, mode="r", encoding="utf-8") as f:
        return f.read()



def get_all_files_by_extension(path, extension="*"):
    files = listdir(path)

    result = dict()

    for file in files:
        if extension == "*" or file.endswith(extension):
            result[file[:-len(extension)]] = file_content(path + "\\" + file)

    return result


def create_directory(path):
    if exists(path):
        return False
    mkdir(path)
    return True