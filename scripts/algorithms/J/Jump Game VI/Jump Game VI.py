// Runtime: 791 ms (Top 67.87%) | Memory: 30.60 MB (Top 42.3%)

class Solution:
    def maxResult(self, nums, k):
        deq, n = deque([0]), len(nums)

        for i in range(1, n):
            while deq and deq[0] < i - k: deq.popleft()
            nums[i] += nums[deq[0]]   
            while deq and nums[i] >= nums[deq[-1]]: deq.pop()
            deq.append(i)
            
        return nums[-1]
