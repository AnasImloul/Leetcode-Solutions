# Runtime: 37 ms (Top 96.56%) | Memory: 14 MB (Top 93.15%)
#Baraa
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        """
        what is (x * (x + 1)) // 2? this is series sum formula between n and 1

        which means: n + (n - 1) + (n - 2) + (n - 3) .... + 1

        when we have a total number of 10 elements that form an arithmetic sum
        eg: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

        we can form subarrays up until count - 2
        which means 1,2,3,4,5,6,7,8
        if we take 7 for example --> [7, 8, 9, 10] or [7, 8, 9]

        we cant take [9, 10] as subarray as its length < 3
        """

        #this is done for termination only
        nums += [-float("inf")]
        n = len(nums)
        #base case
        if n < 3:
            return 0
        res = 0
        #store inital difference we have
        prev_diff = nums[1] - nums[0]
        #because we calculated an initial difference we store 2 inside count
        #which represents number of elements
        count = 2
        for i in range(2, n):
            diff = nums[i] - nums[i - 1]
            if prev_diff != diff:
                x = count - 2
                res = res + (x * (x + 1)) // 2
                prev_diff = diff
                count = 2
            else:
                count += 1
                prev_diff = diff
        return res