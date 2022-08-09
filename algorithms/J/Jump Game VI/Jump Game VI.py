class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        deq = deque([n-1])
        for i in range(n-2, -1, -1):
            if deq[0] - i > k: deq.popleft()
            nums[i] += nums[deq[0]]
            while len(deq) and nums[deq[-1]] <= nums[i]: deq.pop()
            deq.append(i)
        return nums[0]
