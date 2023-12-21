// Runtime: 518 ms (Top 100.0%) | Memory: 31.40 MB (Top 59.67%)

class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        def most_frequent(data):
            # Create Counter object, which is a dictionary subclass for counting hashable objects.
            counter = Counter(data)
            
            # Initialize max_count and max_item
            max_count = -1
            max_item = None

            # Iterate over dictionary items
            for item, count in counter.items():
                # Update max_item and max_count if a higher count is found
                if count > max_count:
                    max_count = count
                    max_item = item

            return max_item, max_count
        

        dom, cnt = most_frequent(nums) # returns dominant number and it's count
        left, right = 0, cnt
        for i in range(n):
            if nums[i] == dom:
                left += 1
                right -= 1
            if left * 2 > i + 1 and right * 2 > n - (i + 1):
                return i
        
        return -1
