import re
import pyparsing


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


def extract_clean_code(code, html=True):
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
    file = file.\
        replace('"', '').\
        replace('*', '').\
        replace(':', '').\
        replace('?', '').\
        replace('\\', '').\
        replace('/', '').\
        replace('|', '').\
        replace('>', '').\
        replace('<', '')
    return file


def get_functions_name(script, function_declaration="def"):
    return list(map(lambda word:word.split()[-1],re.findall(function_declaration + "\s*\w*", script)))


def get_classes_name(script, class_declaration="class"):
    return list(map(lambda word:word.split()[-1],re.findall(class_declaration + "\s*\w*", script)))


def cpp_style_comment_remover(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " " # note: a space and not an empty string
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)


def remove_comments(source: str, language):
    if language == "python":
        parser = pyparsing.pythonStyleComment
        return parser.suppress().transformString(source)
    else:
        return cpp_style_comment_remover(source)


def get_non_empty_lines(string : str):
    result = []
    lines = string.splitlines()
    for line in lines:
        l = " ".join(line.split())
        if l == "":
            continue
        result.append(l)
    return result