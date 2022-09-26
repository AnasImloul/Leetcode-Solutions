# Runtime: 6903 ms (Top 55.05%) | Memory: 16.2 MB (Top 12.59%)
from math import inf

class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:

        # Initialize the result
        res = inf

        # Sort nums so it is easier to avoid duplication
        nums = sorted(nums)

        # k-sum backtracking
        def backtrack(k=3, start=0, partialTotal=0):
            nonlocal res

            # While k hasn't reach 2
            if k != 2:

                # Pick a number from nums starting from the index of the previously picked number plus 1
                for i in range(start, len(nums)):

                    # If result is equal to target, we can stop the search
                    if res == target:
                        return

                    # To avoid duplication, we skip any number that is the same as the previous number
                    if i > start and nums[i] == nums[i - 1]:
                        continue

                    # Pick a number recursively
                    backtrack(k - 1, i + 1, partialTotal + nums[i])

                return

            # Once we have picked k - 2 numbers
            # Initialize the left and right pointers
            l, r = start, len(nums) - 1

            # Iterate until both pointers crossed
            while l < r:

                # Add all values including at both pointers together
                total = partialTotal + nums[l] + nums[r]

                # The current sum is closer to the target than the previous sum, save it
                res = total if abs(target - total) < abs(target - res) else res

                # If the current sum is greater than the target, decrement the right pointer
                if total > target:
                    r -= 1

                # If the current sum is lesser than the target, increment the left pointer
                elif total < target:
                    l += 1

                # Else, we have the cloest possible sum
                else:
                    return

        backtrack()

        return res