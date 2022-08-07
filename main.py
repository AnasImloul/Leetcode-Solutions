from selenium.webdriver import Chrome
from scraper.solutions import scrap as solution_scrap
from scraper.problemset import scrap as problemset_scrap
from scraper.file_utils import load_json


WEBDRIVER_PATH = r"C:\Users\hp\Desktop\Projects\leetcoder\leetcoder\chromedriver.exe"

with Chrome(WEBDRIVER_PATH) as chrome1:

    # problems = problemset_scrap.fetch(browser=chrome1, save_path=r"C:\Users\hp\Desktop\Projects\Leetcode-solutions\scripts\problemset.json")

    problems = load_json(r"C:\Users\hp\Desktop\Projects\Leetcode-solutions\scripts\problemset.json")

    solution_scrap.fetch(browser=chrome1,
                         save_path=r"C:\Users\hp\Desktop\Projects\Leetcode-solutions\scripts" ,
                         problems=problems,
                         languages=("c++","python","java","javascript")
                         )