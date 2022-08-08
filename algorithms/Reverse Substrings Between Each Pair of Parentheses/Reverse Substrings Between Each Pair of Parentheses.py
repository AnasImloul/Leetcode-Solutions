class Solution:
    def reverseParentheses(self, s: str) -> str:
        def solve(string):
            n = len(string)
            word = ""
            i = 0
            while i <n:
                if string[i] == '(':
                    new = ""
                    count = 0
                    while True:
                        count += 1 if string[i] == '(' else -1 if string[i] == ')' else 0
                        if count == 0: break
                        new += string[i]
                        i += 1
                    i += 1
                    word += solve(new[1:])
                else:
                    word += string[i]
                    i += 1
            return word[::-1]
        return solve(s)[::-1]
    
