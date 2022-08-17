class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        bad = [] # list of bad indices
        if s1 == s2 : return True
        
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                bad.append(i)
                
        if  not (len(bad) == 2): return False 
        
        s1 = list(s1)
        s1[bad[0]], s1[bad[1]] = s1[bad[1]], s1[bad[0]]
        res = ""
        
        for char in s1:
            res += char
        
        return (res == s2)
