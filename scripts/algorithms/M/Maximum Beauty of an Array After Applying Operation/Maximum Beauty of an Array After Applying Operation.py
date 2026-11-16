# Runtime: 222 ms (Top 26.79%) | Memory: 32.30 MB (Top 77.14%)

class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        n = len(nums)
        max_value = 0

        # Step 1: Find the maximum value in the array
        for num in nums:
            if num > max_value:
                max_value = num

        # Step 2: Create an array to track ranges
        range_array = [0] * (max_value + 10)

        # Step 3: Mark ranges for each number in the array
        for num in nums:
            left = max(0, num - k)
            right = min(max_value, num + k) + 1
            range_array[left] += 1
            range_array[right] -= 1

        # Step 4: Calculate prefix sums and find the maximum value
        result = range_array[0]
        for i in range(1, len(range_array)):
            range_array[i] += range_array[i - 1]
            if range_array[i] > result:
                result = range_array[i]

        # Step 5: Return the result
        return result
