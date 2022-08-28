// Runtime: 384 ms (Top 73.70%) | Memory: 15 MB (Top 73.95%)
class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        return list(str(int("".join(map(str,num)))+k))