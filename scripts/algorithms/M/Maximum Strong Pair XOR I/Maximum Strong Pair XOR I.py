# Runtime: 40 ms (Top 45.73%) | Memory: 19.00 MB (Top 89.94%)

class Solution:
    # Function to calculate the maximum XOR of strong pairs in a list.
    def maximumStrongPairXor(self, nums: List[int]) -> int:
        ans = 0

        # Iterate through each pair of numbers in the list.
        for x in nums:
            for y in nums:
                # Check if the pair (x, y) is a strong pair.
                if abs(x - y) <= min(x, y):
                    # Update the maximum XOR value.
                    ans = max(ans, x ^ y)

        # Return the maximum XOR value of strong pairs.
        return ans
