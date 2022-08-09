class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def preprocess(s):
            s1 = []
            for c in s:
                if c == '#' :
                    if s1 != []:
                        s1.pop()
                else:
                    s1.append(c)
            return s1
            
        return preprocess(s) == preprocess(t)
