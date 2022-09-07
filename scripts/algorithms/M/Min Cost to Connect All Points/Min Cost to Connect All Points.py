# Runtime: 2922 ms (Top 60.17%) | Memory: 79.1 MB (Top 76.18%)
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:

        cost = 0
        heap = []

        #set to store past points to prevent cycle
        visited = set([0])

        #i == the index of current point
        i = 0

        while len(visited) < len(points):
            #Add all costs from current point to unreached points to min heap
            for j in range(len(points)):
                if j == i or j in visited:
                    continue
                distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                heapq.heappush(heap, (distance, j))

            #Add new min cost edge
            while True:
                dist, point = heapq.heappop(heap)
                if point not in visited:
                    cost += dist
                    #Add point to visited to prevent cycle
                    visited.add(point)
                    #Update point
                    i = point
                    break

        return cost