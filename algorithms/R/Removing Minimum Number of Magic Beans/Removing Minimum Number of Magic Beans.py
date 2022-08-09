class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        totalSum = sum(beans)
        beanLen = len(beans)
        beans.sort()
        minRm = float('inf')
        for i, bean in enumerate(beans):
            minRm = min(minRm, totalSum - (beanLen - i) * bean)
        return minRm
