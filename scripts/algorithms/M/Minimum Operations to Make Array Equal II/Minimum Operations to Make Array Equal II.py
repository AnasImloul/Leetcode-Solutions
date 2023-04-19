class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        if nums1 == nums2:
            return 0
        
        if not k and nums1 != nums2:
            return -1
            
        diff1, diff2 = 0, 0
        
        for num1, num2 in zip(nums1, nums2):
            if abs(num1 - num2) % k == 0:
                if num1 > num2:
                    diff1 += (num1 - num2) // k
                if num1 < num2:
                    diff2 += (num2 - num1) // k
            else:
                return -1
        
        return (diff1 + diff2) // 2 if diff1 == diff2 else -1