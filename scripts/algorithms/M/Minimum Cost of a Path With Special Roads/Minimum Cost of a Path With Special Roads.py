# Runtime: 66 ms (Top 85.58%) | Memory: 21.50 MB (Top 30.77%)

class Solution:
    def minimumCost(self, start: List[int], target: List[int], specialRoads: List[List[int]]) -> int:

        minHeap = [(0, start[0], start[1])] # cost, r, c
        edges = defaultdict(list)

        for x1, y1, x2, y2, cost in specialRoads:
            # get rid of those edges which are not useful at all since the cost is larger than the absolute distance
            if abs(x2 - x1) + abs(y2 - y1) < cost: 
                continue
            edges[(x1, y1)].append((cost, x2, y2))

        visited = {}
        while minHeap:
            ccost, cr, cc = heappop(minHeap)
            if cr == target[0] and cc == target[1]:
                return ccost
            if (cr, cc) in visited:
                continue
            visited[(cr, cc)] = ccost
            # Case 1. The point is at the starting position of a special road, we use this special road.
            if (cr, cc) in edges:
                for ecost, er, ec in edges[(cr, cc)]:
                    if (er, ec) not in visited:
                        heappush(minHeap, (ccost + ecost, er, ec))
            # Case 2. We can go from the point to a starting position of a special road.
            for sr, sc in edges:
                if (sr, sc) not in visited:
                    heappush(minHeap, (ccost + abs(sr-cr) + abs(sc-cc), sr, sc))
            # Case 3. We can go from the point directly to the target.
            heappush(minHeap, (ccost + abs(target[0]-cr) + abs(target[1]-cc), target[0], target[1]))
