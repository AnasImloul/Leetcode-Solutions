# 1. we can not use sliding window to solve the problem, because the numbers in nums can be negative, 
# the numbers in sliding window are not always incrementing
# ex [8,-4,3,1,6], 10

# 2. prefixsum2 - prefixsum1 >= k is used to find a subarray whose sum >= k.
# 3. monotonic queue is used to keep the prefix sums are in the incrementing order
# 4. If the diffenence between the cur and the tail of monotonic queue is greater than or equal to k, we can find the shortest length of the subarray at this time.

class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        prefixsum = [0]
        monoq = deque()
        minLen = float('inf')
        # to calculate prefix sum
        for n in nums:
            prefixsum.append(n+prefixsum[-1])
        for idx, cur in enumerate(prefixsum):
            while monoq and prefixsum[monoq[-1]] >= cur: monoq.pop() # to maintain monotonic queue

            # If the diffenence between the head and the tail of monotonic queue is greater than or equal to k, we can find the shortest length of the subarray at this time.
            while monoq and cur-prefixsum[monoq[0]]>=k: 
                minLen = min(minLen, idx-monoq.popleft())
            monoq.append(idx)
        return -1 if minLen == float('inf') else minLen
