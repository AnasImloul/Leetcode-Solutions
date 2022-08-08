class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        
        level = 0
        result = 0
        prev = ""
        
        for c in s:           
            if c == "(":
                level += 1
            if c == ")":
                if prev == "(":
                    result += 2 ** (level - 1)
                level -= 1                
            prev = c
            
        return result
