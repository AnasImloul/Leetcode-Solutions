from collections import Counter
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        x = dict(Counter(s1.split() + s2.split()))
        ans = []
        for key in x:
            if x[key] == 1:
                ans.append(key)
                
        return ans