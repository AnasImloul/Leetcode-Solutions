# Runtime: 0 ms (Top 100.00%) | Memory: 19.40 MB (Top 11.97%)

class Solution:                                                 
    def distinctAverages(self, nums: List[int]) -> int:
                                                #   Ex: nums = [4,1,4,0,3,5]
        nums.sort()                             #   nums = [0,1,3,4,4,5]
                                                #        i: 0 1 2 3 4 5

        n = len(nums)                           #   ans = len({0+5,1+4,3+4})
                                                #       = len({5,5,7})
        return len({nums[i]+nums[n-i-1] 
                        for i in range(n//2)})  #       = len({5,7}) = 2 <-- answer
