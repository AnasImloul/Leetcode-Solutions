class Solution(object):
    def subsetsWithDup(self, nums):
        def fn(nums):
            if len(nums)==0:
                return [[]]
            ele=nums[0]
            without=self.subsetsWithDup(nums[1:])
            wit=[]
            for i in without:
                l=[ele]+i
                if l not in without:
                    wit.append(l)
            return without+wit
        return fn(sorted(nums))
