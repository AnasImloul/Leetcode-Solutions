class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        pre = -k - 1
        for i, v in enumerate(nums):
            if v:
                if i - pre < k + 1:
                    return False
                else:
                    pre = i
        return True
        
