class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        
        g = [[] for _ in range(n)]
        for i,j in edges:
            g[i-1] += [j-1]
            g[j-1] += [i-1]
        q = queue.Queue()
        q.put((0,1,-1,0))
        while not q.empty():
            node,p,parent,rem = q.get()
            if node == target - 1 and rem == t:
                return p
            if rem <= t:
                rem += 1
            else:
                break
            if parent != -1:
                g[node].remove(parent)
            neighbours_len = len(g[node])
            if neighbours_len == 0:
                q.put((node,p,-1,rem))
            for neighbour in g[node]:
                q.put((neighbour,p*(1/neighbours_len),node,rem))
            
        return 0
