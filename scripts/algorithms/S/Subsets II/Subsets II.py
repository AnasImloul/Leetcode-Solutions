class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        def subset(p, up):
            if len(up) == 0:
                if p not in ans:
                    ans.append(p)
                return 
            ch = up[0]
            subset(p+[ch], up[1:])
            subset(p, up[1:])
        subset([], nums)
        return ans