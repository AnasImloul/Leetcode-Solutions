class Solution:
    def isSub(self, s1, s2):
        n = len(s1)
        i = 0
        for c in s2:
            if i >= n:
                break
            if s1[i] == c:
                i += 1
        return i == n
    
    def findLUSlength(self, strs: List[str]) -> int:
        n = len(strs)
        strs.sort(key = lambda s: -len(s))
        for i in range(n):
            valid = True
            for j in range(n):
                if i != j and self.isSub(strs[i], strs[j]):
                    valid = False
                    break
            if valid:
                return len(strs[i])
        return -1
