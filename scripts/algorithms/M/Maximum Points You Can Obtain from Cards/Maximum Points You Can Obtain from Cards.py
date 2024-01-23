// Runtime: 314 ms (Top 86.56%) | Memory: 29.90 MB (Top 66.7%)

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        total = sum(cardPoints)
        
        remaining_length = n - k
        subarray_sum = sum(cardPoints[:remaining_length])
        
        min_sum = subarray_sum
        for i in range(remaining_length, n):
            # Update the sliding window sum to the subarray ending at index i
            subarray_sum += cardPoints[i]
            subarray_sum -= cardPoints[i - remaining_length]
            # Update min_sum to track the overall minimum sum so far
            min_sum = min(min_sum, subarray_sum)
        return total - min_sum
