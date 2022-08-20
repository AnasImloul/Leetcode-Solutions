# Runtime: 90 ms (Top 72.15%) | Memory: 15.1 MB (Top 64.41%)

class Solution:

    def twoSum(self, nums: List[int], target: int) -> List[int]:

        arr = dict()
        # store the index of each number in the array
        for i,num in enumerate(nums):
            arr[num] = i

    # iterate one more time over the array to check if there is any element which complement is in the array
        for j, num in enumerate(nums):
            rest = target - num
            if arr.get(rest, j) != j:
                return [j, arr[rest]]