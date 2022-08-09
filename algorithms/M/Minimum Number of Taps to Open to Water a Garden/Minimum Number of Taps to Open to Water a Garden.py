class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        maxRanges = [0]
        for i in range(len(ranges)):
            minIdx = max(i - ranges[i], 0)
            maxIdx = min(i + ranges[i], n)
            idx = bisect_left(maxRanges, minIdx)
            if idx == len(maxRanges) or maxIdx <= maxRanges[idx]: continue
            if idx == len(maxRanges) - 1:
                maxRanges.append(maxIdx)
            else:
                maxRanges[idx + 1] = max(maxRanges[idx + 1], maxIdx)
        if maxRanges[-1] < n:
            return -1
        else:
            return len(maxRanges) - 1
