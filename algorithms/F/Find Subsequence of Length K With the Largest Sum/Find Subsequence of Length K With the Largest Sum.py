class Solution(object):
    def maxSubsequence(self, nums, k):
        ret, max_k = [], sorted(nums, reverse=True)[:k]
        for num in nums:
            if num in max_k:
                ret.append(num)
                max_k.remove(num)
                if len(max_k) == 0:
                    return ret
