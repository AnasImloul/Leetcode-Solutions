# Runtime: 665 ms (Top 16.32%) | Memory: 15 MB (Top 51.03%)

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        return list(str(int("".join(map(str,num)))+k))