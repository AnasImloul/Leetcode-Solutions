class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort(reverse=True)
        maxSatisfaction = dishSum = 0

        for dish in satisfaction:
            dishSum += dish
            if dishSum <= 0:
                break
            maxSatisfaction += dishSum
        
        return maxSatisfaction