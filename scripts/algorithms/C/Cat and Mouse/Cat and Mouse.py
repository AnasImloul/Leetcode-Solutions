class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        def getPreStates(m,c,t):
            ans = []
            if t == 1:
                for c2 in graph[c]:
                    if c2 == 0:continue
                    ans.append((m,c2,2))
            else:
                for m2 in graph[m]:
                    ans.append((m2,c,1))
            return ans
        
        def ifAllNextMovesFailed(m,c,t):
            if t == 1:
                for m2 in graph[m]:
                    if result[(m2,c,2)] != 2:return False
            else:
                for c2 in graph[c]:
                    if c2 == 0:continue
                    if result[(m,c2,1)] != 1:return False
            return True
        
        result = defaultdict(lambda:0) 
        # key = (m,c,turn) value = (0/1/2)
        n = len(graph)
        queue = deque()
        
        for t in range(1,3):
            for i in range(1,n):
                # mouse win 
                result[(0,i,t)] = 1
                queue.append((0,i,t))
                # cat win
                result[(i,i,t)] = 2
                queue.append((i,i,t))
        
        while queue:
            m,c,t = queue.popleft()
            r = result[(m,c,t)]
            for m2,c2,t2 in getPreStates(m,c,t):
                r2 = result[(m2,c2,t2)]
                if r2 > 0:continue
                # populate prestate
                if r == 3-t: # can always win
                    result[(m2,c2,t2)] = r
                    queue.append((m2,c2,t2))
                elif ifAllNextMovesFailed(m2,c2,t2):
                    result[(m2,c2,t2)] =3-t2
                    queue.append((m2,c2,t2))
        return result[(1,2,1)]
                    
