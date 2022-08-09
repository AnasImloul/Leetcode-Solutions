from collections import Counter
class Solution:
    def sortString(self, s: str) -> str:
        counter = Counter(s)
        alphabets = "abcdefghijklmnopqrstuvwxyz"
        rev_alphabets = alphabets[::-1]
        total = len(s)
        res = []
        while total > 0:
            for c in alphabets:
                if counter[c]: 
                    res.append(c)
                    counter[c] -= 1
                    total -= 1
            for c in rev_alphabets:
                if counter[c]:
                    res.append(c)
                    counter[c] -= 1
                    total -= 1
        return "".join(res)