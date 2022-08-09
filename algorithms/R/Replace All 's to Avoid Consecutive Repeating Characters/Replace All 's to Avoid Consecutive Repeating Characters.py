class Solution:
    def modifyString(self, s: str) -> str:
        s = list(s)
        abc = set(['a','b','c'])
        for i, c in enumerate(s):
            if c == '?':
                neib = set()
                if i != 0:
                    neib.add(s[i-1])
                if i != len(s)-1:
                    neib.add(s[i+1])
                s[i] = (abc-neib).pop()
        return "".join(s)