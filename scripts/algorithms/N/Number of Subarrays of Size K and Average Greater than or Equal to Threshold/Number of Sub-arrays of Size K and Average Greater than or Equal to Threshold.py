# Runtime: 1018 ms (Top 58.37%) | Memory: 27.3 MB (Top 53.27%)
class Solution:
    def numOfSubarrays(self, nums: List[int], k: int, threshold: int) -> int:
        currSum = 0
        start = 0
        end = 0
        count = 0

        # run right pointer till end element
        for end in range(len(nums)):
            # update value to window
            currSum += nums[end]

            # check if window size achieved
            if (end - start + 1) == k:
                # is average > target val
                if (currSum // k) >= threshold:
                    count += 1
                # slide the window
                currSum -= nums[start]
                start += 1

        return count