# Runtime: 1682 ms (Top 100.0%) | Memory: 18.40 MB (Top 71.7%)

class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:        
        n = len(nums)
        graph = [[] for _ in range(n)]
        for u, v in edges: 
            graph[u].append(v)
            graph[v].append(u)
            
        def fn(u, p): 
            nonlocal t
            score[u] = nums[u]
            tin[u] = (t := t+1) # time to enter
            for v in graph[u]: 
                if v != p: 
                    fn(v, u)
                    score[u] ^= score[v]
            tout[u] = t # time to exit 
        
        t = 0 
        score = [0]*n
        tin = [0]*n 
        tout = [0]*n 
        fn(0, -1)
        
        ans = inf 
        for u in range(1, n): 
            for v in range(u+1, n): 
                if tin[v] <= tin[u] and tout[v] >= tout[u]: # enter earlier & exit later == parent 
                    uu = score[u]
                    vv = score[v] ^ score[u]
                    xx = score[0] ^ score[v]
                elif tin[v] >= tin[u] and tout[v] <= tout[u]: 
                    uu = score[u] ^ score[v]
                    vv = score[v]
                    xx = score[0] ^ score[u]
                else: 
                    uu = score[u]
                    vv = score[v]
                    xx = score[0] ^ score[u] ^ score[v]
                ans = min(ans, max(uu, vv, xx) - min(uu, vv, xx))
        return ans  