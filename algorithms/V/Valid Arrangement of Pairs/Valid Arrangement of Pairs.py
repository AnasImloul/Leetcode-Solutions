#Hierholzer Algorithm
from collections import defaultdict
class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        G = defaultdict(list)
        din = defaultdict(int)
        dout = defaultdict(int)
        for v, w in pairs:
            G[v].append(w)
            dout[v] += 1
            din[w] += 1
        start = pairs[0][0]
        for v in G:
            if din[v]+1 == dout[v]:
                start = v
        route = []
        def dfs(v):
            while G[v]:
                w = G[v].pop()
                dfs(w)
            route.append(v)
        dfs(start)
        route.reverse()
        return [[route[i],route[i+1]] for i in range(len(route)-1)]
