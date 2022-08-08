class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        res = []
        ch= []
        for i in range(len(s)):
            if s[i] == c:
                ch.append(i)
        min_d = len(s)
        for i in range(len(s)):
            for j in range(len(ch)):
                min_d = min(min_d, abs(i-ch[j]))
            res.append(min_d)
            min_d = len(s)
        return res
