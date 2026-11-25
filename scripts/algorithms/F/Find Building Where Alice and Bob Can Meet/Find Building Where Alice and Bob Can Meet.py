# Runtime: 674 ms (Top 38.28%) | Memory: 44.90 MB (Top 66.51%)

class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        res, idx = [0] * len(queries), []
        for i, q in enumerate(queries):
            a, b = sorted(q)
            if a == b or heights[a] < heights[b]:
                res[i] = b
            else:
                idx.append((a, b, i))
        j, mono = len(heights) - 1, deque()
        for a, b, i in sorted(idx, key=itemgetter(1), reverse=True):
            while j > b:
                while mono and heights[mono[0]] < heights[j]:
                    mono.popleft()
                mono.appendleft(j)
                j -= 1
            k = bisect_right(mono, heights[a], key=lambda x: heights[x])
            res[i] = -1 if k == len(mono) else mono[k]
        return res
