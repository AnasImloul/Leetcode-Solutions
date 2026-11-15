# Runtime: 0 ms (Top 100.00%) | Memory: 19.20 MB (Top 80.37%)

class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        contains_zero = False
        positive = []
        negative = []

        for num in nums:
            if num > 0:
                positive.append(num)
            elif num < 0:
                negative.append(num)
            else:
                contains_zero = True

        # If the product of negative numbers is negative
        if len(negative) & 1:
            # If there is more than one negative number,
            # then their product can be positive.
            if len(negative) > 1:
                negative.remove(max(negative))
            # If not, then the product of positive numbers is sufficient
            elif positive:
                return prod(positive)
            # If not again, then zero is greater than negative numbers.
            elif contains_zero:
                return 0
            # If again not, then return the maximum among the negative
            else:
                return max(negative)

        # Consists of zeros only
        if not (negative or positive):
            return 0

        return prod(negative) * prod(positive)
