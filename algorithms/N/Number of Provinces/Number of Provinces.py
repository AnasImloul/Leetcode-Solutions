class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        graph = defaultdict(list)
        for i,x in enumerate(isConnected):
            for j,n in enumerate(x):
                if j!=i and n == 1:
                    graph[i].append(j)
            
        visit = set()
        
        def dfs(node):
            if node not in graph:
                return 
            for neighbor in graph[node]:
                if neighbor not in visit:
                    visit.add(neighbor)
                    dfs(neighbor)
        count = 0
        for i in range(len(isConnected)):
            if i in visit:
                continue
            count+=1
            dfs(i)
        return count
