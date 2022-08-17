class Solution:
    def checkWays(self, P):
        g = defaultdict(set)
        for u, v in P:
            g[u].add(v)
            g[v].add(u)

        def helper(nodes):
            d, m = defaultdict(list), len(nodes) - 1
            for node in nodes:
                d[len(g[node])].append(node)

            if len(d[m]) == 0: return 0
            root = d[m][0]
            
            for node in g[root]: g[node].remove(root)
            
            comps, seen, i = defaultdict(set), set(), 0
            def dfs(node, i):
                comps[i].add(node)
                seen.add(node)
                for neib in g[node]:
                    if neib not in seen: dfs(neib, i)
                        
            for node in nodes:
                if node != root and node not in seen:
                    dfs(node, i)
                    i += 1
                    
            cands = [helper(comps[i]) for i in comps]
            if 0 in cands: return 0
            if 2 in cands: return 2
            if len(d[m]) >= 2: return 2
            return 1
            
        return helper(set(g.keys()))
