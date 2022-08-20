# Runtime: 577 ms (Top 67.14%) | Memory: 27 MB (Top 83.15%)

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        total_cards = len(cardPoints)
        total = sum(cardPoints)
        window_size = total_cards - k
        window_total = 0

        if total_cards == k:
            return total

        for i in range(total_cards - k):
            window_total += cardPoints[i]
        max_diff = total - window_total
        for i in range((total_cards - k), total_cards):
            window_total += cardPoints[i]
            window_total -= cardPoints[i-window_size]
            if total - window_total > max_diff:
                max_diff = total - window_total
        return max_diff