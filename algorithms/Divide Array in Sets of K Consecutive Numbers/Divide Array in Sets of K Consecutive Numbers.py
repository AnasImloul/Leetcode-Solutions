class Solution(object):
    def isPossibleDivide(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums) % k != 0:
            return False
        
        freq = collections.defaultdict(int)
        for v in nums:
            freq[v] += 1
            
        nums.sort()
        while sum(freq.values()) > 0:
			# smallest number in sorted nums with freq > 0 to start a sequence [v, v+1, v+2 ... , v+k-1]
            for v in nums: 
                if freq[v] > 0: 
                    for i in range(k):
                        if freq[v+i] <= 0:
                            return False
                        else:
                            freq[v+i] -= 1
        return True
