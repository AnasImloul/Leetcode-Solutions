class Solution:
    def isValid(self, string: str) -> bool:
         while True:
            if '()' in string:
                string = string.replace('()', '')
            elif '{}' in string:
                string = string.replace('{}', '')
            elif '[]' in string:
                string = string.replace('[]', '')

            else:
                return not string
