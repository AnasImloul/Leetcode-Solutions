// Runtime: 194 ms (Top 22.81%) | Memory: 17.70 MB (Top 6.09%)

class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        ans = []
        
        def find_diffs(arr):
            
            arr.sort()

            dif = []
            
            for i in range(len(arr) - 1):
                dif.append(arr[i] - arr[i + 1])
            
            return len(set(dif)) == 1
        
        for i , j in zip(l , r):
            ans.append(find_diffs(nums[i:j + 1]))
        
        return ans
