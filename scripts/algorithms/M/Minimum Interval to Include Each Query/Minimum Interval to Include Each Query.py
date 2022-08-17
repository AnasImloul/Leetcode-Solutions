class Solution:
    def minInterval(self, intervals: List[List[int]], queries: List[int]) -> List[int]:
        ans = [-1] * len(queries)
        intervals.sort(key = lambda i: i[1] - i[0])
        queries = sorted([q, i] for i, q in enumerate(queries))
        for left, right in intervals:
            idx = bisect.bisect(queries, [left])
            while idx < len(queries) and queries[idx][0] <= right:
                ans[queries.pop(idx)[1]] = right - left + 1
        return ans
