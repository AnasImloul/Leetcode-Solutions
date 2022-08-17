from collections import Counter

class Solution:
    def digitCount(self, num: str) -> bool:
        d = Counter(num)
        for i in range(len(num)):
            if int(num[i])!=d.get(str(i), 0):
                return False
        return True
