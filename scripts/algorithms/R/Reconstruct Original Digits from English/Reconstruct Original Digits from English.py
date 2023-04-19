class Solution:
    def originalDigits(self, s: str) -> str:
        c = dict()
        
        c[0] = s.count("z")
        c[2] = s.count("w")
        c[4] = s.count("u")
        c[6] = s.count("x")
        c[8] = s.count("g")
        
        c[3] = s.count("h") - c[8]
        c[5] = s.count("f") - c[4]
        c[7] = s.count("s") - c[6]
        
        c[9] = s.count("i") - (c[8] + c[5] + c[6])
        c[1] = s.count("o") - (c[0] + c[2] + c[4])
        
        c = sorted(c.items(), key = lambda x: x[0])
        ans = ""
        for k, v in c:
            ans += (str(k) * v)
        return ans