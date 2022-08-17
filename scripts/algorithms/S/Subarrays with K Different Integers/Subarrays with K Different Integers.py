class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.lengthOfLongestSubstringKDistinct(nums, k) - self.lengthOfLongestSubstringKDistinct(nums, k-1)
    
    def lengthOfLongestSubstringKDistinct(self, s, k):
        n = len(s)
        if n * k == 0:
            return 0
        left = 0

        hashmap = collections.OrderedDict()

        subarray = 0
        for right in range(n):
            if s[right] in hashmap:
                del hashmap[s[right]]
            hashmap[s[right]] = right

            if len(hashmap) == k + 1:
                _, del_idx = hashmap.popitem(last = False)
                left = del_idx + 1
            subarray += right - left + 1

        return subarray
    
    
            
