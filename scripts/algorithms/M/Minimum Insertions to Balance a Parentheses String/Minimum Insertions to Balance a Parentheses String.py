class Solution:
    def minInsertions(self, s: str) -> int:
        leftbrackets = insertions = 0
        i, n = 0, len(s)

        while i < n:
            if s[i] == '(':
                leftbrackets += 1
            elif s[i] == ')':
                if i == n-1 or s[i+1] != ')': insertions += 1
                else: i += 1
                    
                if not leftbrackets: insertions += 1
                else: leftbrackets -= 1
                    
            i += 1
        
        return leftbrackets * 2 + insertions