class DSUF:
    def __init__(self, n):
        self.arr = [-1] * n
    def find(self, node):
        p = self.arr[node]
        if p == -1:
            return node
        self.arr[node] = self.find(p)
        return self.arr[node]
    def union(self, a, b):
        aP = self.find(a)
        bP = self.find(b)
        if aP == bP:
            return 0
        self.arr[aP] = bP
        return 1
    def countParents(self):
        count = 0
        for i in self.arr:
            if i == -1:
                count += 1
        return count

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        # Solution - DSU
        # Time - O(ElogV)
        # Space - O(V)
        
        aliceSet = DSUF(n)
        bobSet = DSUF(n)
        
        bothEdges = []
        bobEdges = []
        aliceEdges= []
        for i in range(len(edges)):
            if edges[i][0] == 3:
                bothEdges.append(edges[i])
            elif edges[i][0] == 1:
                aliceEdges.append(edges[i])
            else:
                bobEdges.append(edges[i])
        
        usedEdgeCount = 0
        
        # connect both edges
        for edge in bothEdges:
            aReq = aliceSet.union(edge[1]-1, edge[2]-1)
            bReq = bobSet.union(edge[1]-1, edge[2]-1)
            if aReq and bReq:
                usedEdgeCount += 1
        
        # connect individual edges
        for edge in aliceEdges:
            usedEdgeCount += aliceSet.union(edge[1]-1, edge[2]-1)
        
        for edge in bobEdges:
            usedEdgeCount += bobSet.union(edge[1]-1, edge[2]-1)
        
        if aliceSet.countParents() == 1 and bobSet.countParents() == 1:
            return len(edges) - usedEdgeCount
        
        return -1
