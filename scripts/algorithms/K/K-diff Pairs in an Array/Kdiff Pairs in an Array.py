class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        
        # initialize hash table
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
        
        # iterate through array and find pairs
        count = 0
        for num in freq:
            if k == 0:
                if freq[num] > 1:
                    count += 1
            else:
                if num + k in freq:
                    count += 1
        
        # return count of unique pairs
        return count
