class Solution:
    def timeRequiredToBuy(self, t: List[int], k: int) -> int:
        return sum(min(v, t[k] if i <= k else t[k] - 1) for i, v in enumerate(t))
