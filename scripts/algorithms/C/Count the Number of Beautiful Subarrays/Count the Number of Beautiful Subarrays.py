# Runtime: 820 ms (Top 100.0%) | Memory: 35.77 MB (Top 50.0%)

class Solution(object):
    def beautifulSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        prefix = nums[0]
        hashmap = defaultdict(int)
        hashmap[0] = 1
        
        cnt = 0
        
        for i in xrange(0, len(nums)):
            if i>0: prefix = nums[i] ^ prefix
            if prefix in hashmap:
               # print(i, prefix)
               cnt += hashmap[prefix]
            hashmap[prefix] += 1
            
        return cnt
        
        