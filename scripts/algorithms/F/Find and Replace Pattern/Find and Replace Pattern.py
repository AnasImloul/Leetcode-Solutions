# Runtime: 34 ms (Top 93.54%) | Memory: 13.8 MB (Top 81.83%)
class Solution:
    def findAndReplacePattern(self, words: List[str], p: str) -> List[str]:
        def find(w): # function thats calculate the numeric pattern
            l = []
            m = defaultdict(int)
            i = 0
            for c in w:
                if c in m:
                    l.append(m[c])
                else:
                    i+=1
                    m[c]=i
                    l.append(m[c])
            return l
        ans = []
        pfind = find(p)
        for w in words:
            wfind = find(w)
            if wfind == pfind: ans.append(w) #check if numeric pattern of pattern is equal to pattern of word
        return ans