class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        visited = [False for _ in range(n)]
        pc = [] # Store the parent child edge node in our dfs
        adj = [[] for _ in range(n)]
        
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        childs = [[False for _ in range(n)] for _ in range(n)] # To store if node a contains b as on of its child tree
        child_xor = [0 for _ in range(n)] # To store the xor of node a and all its child tree
        par = [] to store parents of a node a while doing DFS
        
        def dfs(i: int) -> int:
            ans = nums[i]
            visited[i] = True
            
            for p in par: childs[p][i] = True
                
            par.append(i)
            
            for child in adj[i]:
                if (not visited[child]):
                    pc.append([i, child])
                    ans ^= dfs(child)
            
            par.pop()
            child_xor[i] = ans
            
            return ans
        
        dfs(0)
        
        ans = 1000000000
        
        for i in range(len(pc)):
            for j in range(i + 1, len(pc)):
                (a, b) = (pc[i][1], pc[j][1])
				(xa, xb, xc) = (child_xor[a], child_xor[b], child_xor[0])
                
                if childs[a][b]: # here a is an ancestor of b or a has b in its child tree
                    xc ^= xa
                    xa ^= xb
                else:
                    xc ^= xa
                    xc ^= xb
                
                ans = min(max(xa, xb, xc) - min(xa, xb, xc), ans)
        
        return ans
