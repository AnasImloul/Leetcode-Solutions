# Runtime: 18 ms (Top 39.15%) | Memory: 19.20 MB (Top 85.01%)

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums) 
        distinct_elements = len(set(nums)) 
        count = 0 
        left = 0 
        right = 0 
        counter = Counter() 

        while right < n: 
            counter[nums[right]] += 1 
            while len(counter) == distinct_elements: 
                counter[nums[left]] -= 1 
                if counter[nums[left]] == 0: 
                    del counter[nums[left]] 
                left += 1 
                count += n - right 
            right += 1 

        return count
