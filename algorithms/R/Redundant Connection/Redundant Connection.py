class UnionFind:
    
    def __init__(self, size):
        
        self.parent = [-1 for _ in range(size)]
        self.rank = [-1 for _ in range(size)]
        
    def find(self, i):
        
        if self.parent[i] == -1:
            return i
        
        k = self.find(self.parent[i])
        self.parent[i] = k
        return k
    
    def union(self, x, y):
        
        x = self.find(x)
        y = self.find(y)
        
        if x == y:
            return -1
        else:
            
            if self.rank[x] > self.rank[y]:
                self.parent[y] = x
            
            elif self.rank[x] < self.rank[y]:
                self.parent[x] = y
                
            else:
                self.rank[x] += 1
                self.parent[y] = x

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
   
        vertex_set = set()
    
        for edge in edges:
            vertex_set.add(edge[0])
            vertex_set.add(edge[1])
        
        
        union_find = UnionFind(len(vertex_set))
        
        for edge in edges:
            
            new_edge = [edge[0]-1, edge[1]-1]
            
            if union_find.union(new_edge[0], new_edge[1]) == -1:
                return edge
        
        return []

