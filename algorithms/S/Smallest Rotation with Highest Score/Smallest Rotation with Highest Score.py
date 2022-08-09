class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        diff = [i - nums[i] for i in range(len(nums))]
        
        target = 0
        qualified = []
        for d in diff:
            if d >= target:
                heappush(qualified, d)
        smallest_rotate = 0
        highest_score = len(qualified)
        
        
        for rotate in range(1, len(nums)):
            target += 1
            while qualified and qualified[0] < target:
                heappop(qualified)
            modified = diff[rotate-1] + len(diff)
            heappush(qualified, modified)
            score = len(qualified)
            if score > highest_score:
                smallest_rotate = rotate
                highest_score = score
        
        return smallest_rotate

