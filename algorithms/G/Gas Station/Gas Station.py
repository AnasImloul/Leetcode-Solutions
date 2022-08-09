class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        deltas = [x-y for x, y in zip(gas, cost)]
        n = len(deltas)
        deltas = deltas + deltas
        cursum, curi = 0, 0
        maxsum, maxi = 0, 0
        for i, delta in enumerate(deltas):
            cursum = max(0, cursum + delta)
            if cursum == 0:
                curi = i+1
            if cursum > maxsum:
                maxi = curi
                maxsum = cursum
        cursum = 0
        for i in range(n):
            cursum += deltas[(maxi+i)%n]
            if cursum < 0: return -1
        return maxi