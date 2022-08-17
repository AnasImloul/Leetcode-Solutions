from collections import defaultdict
class Solution:
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        st = defaultdict(lambda : -1)
        ed = defaultdict(int)
        for i, c in enumerate(s):
            if st[c]==-1:
                st[c] = i
                ed[c] = i
            else:
                ed[c] = i
        ints = []
        for c in set(s):
            b, e = st[c], ed[c]
            i = b
            while i <= e and b == st[c]:
                b = min(b, st[s[i]])
                e = max(e, ed[s[i]])
                i += 1
            if b == st[c]:
                ints.append((b,e))
        ints.sort(key = lambda e: e[1])
        res = []
        prev = -1
        for i in range(len(ints)):
            j,k = ints[i]
            if j > prev:
                res.append(s[j:k+1])
                prev = k
        return res