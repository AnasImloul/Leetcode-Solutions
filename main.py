from selenium.webdriver import Chrome
from scraper.solutions import scrap as solution_scrap
from scraper.problemset import scrap as problemset_scrap

from os import getcwd




PATH = getcwd()

WEBDRIVER_PATH = r"C:\Users\hp\Desktop\Projects\leetcoder\leetcoder\chromedriver.exe"

with Chrome(WEBDRIVER_PATH) as chrome1:

    #problems = problemset_scrap.fetch(browser=chrome1, save_path=PATH+r"\scraper\problemset\problemset.json", premium=False)

    problems = load_json(PATH+r"\scraper\problemset\problemset.json")

    solution_scrap.fetch(browser=chrome1,
                         save_path=PATH + r"\scripts",
                         problems=problems,
                         languages=("c++","python","java","javascript")
                         )

