// Runtime: 40 ms (Top 71.65%) | Memory: 17.30 MB (Top 26.77%)

class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def isSubseq(a, b):
            j = 0
            for i in range(len(b)):
                if a[j] == b[i]:
                    j += 1
                    if j == len(a):
                        return True
            return False
        c = Counter(strs)
        s = sorted(c.keys(), key=len, reverse=True)
        for i in range(len(s)):
            if c[s[i]] > 1:
                continue
            if i == 0 or not any(isSubseq(s[i], s[j]) for j in range(i)):    
                return len(s[i])
        return -1 
