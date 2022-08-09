class Solution:
    def mostFrequent(self, nums, key):
        counts = {}
        
        for i in range(1,len(nums)):
            if nums[i-1]==key:
                if nums[i] not in counts: counts[nums[i]] = 1
                else: counts[nums[i]] += 1
        
        return max(counts, key=counts.get)
