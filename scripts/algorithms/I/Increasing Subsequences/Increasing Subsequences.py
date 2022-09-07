# Runtime: 750 ms (Top 10.08%) | Memory: 22.4 MB (Top 30.72%)
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        def backtracking(nums,path):
           # to ensure that the base array has at least 2 elements
            if len(path)>=2:
                res.add(tuple(path))
            for i in range(len(nums)):
                # to ensure that every element to be added is equal or larger than the former
                if not path or path[-1] <= nums[i]:
                    backtracking(nums[i+1:],path+[nums[i]])

        res=set()
        backtracking(nums,[])
        return res