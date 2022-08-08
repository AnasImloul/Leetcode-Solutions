class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def _f(s):
            d = Counter(s)
            d =dict(sorted(d.items(), key=lambda item: item[0]))
            for x in d:
                return d[x]
        
        freq = []
        for w in words:
            n1 = _f(w)
            freq.append(n1)
        
        freq.sort(reverse=True)

        res = []
        for q in queries:
            n = _f(q)
            c=0
            for n1 in freq:
                if n < n1:
                    c+=1
                else:
                    break
            res.append(c)
        
        return res
