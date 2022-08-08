class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        g = [[[] for _ in range(2)] for _ in range(n)]
        
        for i,j in redEdges:
            g[i][0] += [j]
        for i,j in blueEdges:
            g[i][1] += [j]
        distance = [float("inf") for _ in range(n)]
        distance[0] = 0
        q = queue.Queue()
        q.put((0,0,False))
        q.put((0,0,True))
        
        redS = set([0])
        blueS = set([0])
        while not q.empty():
            node,dist,red = q.get()
            if red:
                neighbours = g[node][0]
                redS.add(node)
                curr = blueS
            else:
                neighbours = g[node][1]
                blueS.add(node)
                curr = redS
            for neighbour in neighbours:
                if dist + 1 < distance[neighbour]:
                    distance[neighbour] = dist + 1
                    q.put((neighbour,dist + 1,not red))
                if not (neighbour in curr):
                    q.put((neighbour,dist + 1,not red))
        for i in range(n):
            if distance[i] == float("inf"):
                distance[i] = -1
        return distance
            
