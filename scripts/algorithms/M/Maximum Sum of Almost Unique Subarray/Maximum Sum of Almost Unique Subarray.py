# Runtime: 81 ms (Top 79.54%) | Memory: 22.70 MB (Top 89.30%)

class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        maxSum = 0
        currentSum = 0
        elementFrequency = {}
        left = 0

        for right in range(len(nums)):
            currentElement = nums[right]

            # Update frequency and sum
            elementFrequency[currentElement] = elementFrequency.get(currentElement, 0) + 1
            currentSum += currentElement

            # Shrink the window if it exceeds k elements
            while right - left + 1 > k:
                leftElement = nums[left]

                # Update frequency and sum
                elementFrequency[leftElement] -= 1
                if elementFrequency[leftElement] == 0:
                    del elementFrequency[leftElement]
                currentSum -= leftElement

                # Move the left pointer to shrink the window
                left += 1

            # Check if the subarray has at least m distinct elements
            if len(elementFrequency) >= m:
                maxSum = max(maxSum, currentSum)

        return maxSum
