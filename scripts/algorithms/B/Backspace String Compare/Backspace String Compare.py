class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def backwardResult(string):
            debt = 0
            
            for c in reversed(string):
                if c == '#':
                    debt += 1
                
                elif debt > 0:
                    debt -= 1
                
                else:
                    yield c
        
        return all(a == b for (a, b) in zip_longest(backwardResult(s), backwardResult(t)))