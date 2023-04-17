# TC : O(N)
# SC : O(1)
class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        z_count = 0 #count zeors in nums
        mx_ones = 0
        j = 0
        for i in range(len(nums)):
            if nums[i] == 0: 
                z_count+=1
            while z_count>k:#if zeros count cross k decrease count
                if nums[j] == 0:
                    z_count-=1
                j+=1
            print(i,j)
            mx_ones = max(mx_ones, i-j+1)
        return mx_ones
