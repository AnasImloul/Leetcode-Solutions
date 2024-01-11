// Runtime: 70 ms (Top 94.47%) | Memory: 17.40 MB (Top 33.41%)

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        n, m = len(target), len(arr)
        if m > n:
            return False
        t = Counter(target)
        a = Counter(arr)
        for k, v in a.items():
            if k in t and v == t[k]:
                continue
            else:
                return False
        return True
