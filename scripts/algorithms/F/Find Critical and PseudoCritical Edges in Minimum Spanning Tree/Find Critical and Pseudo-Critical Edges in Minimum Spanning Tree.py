# Runtime: 4066 ms (Top 12.97%) | Memory: 14.1 MB (Top 87.04%)
class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        def find(v, parent):
            if parent[v] != v:
                parent[v] = find(parent[v], parent)
            return parent[v]
        def union(u,v, parent):
            parent[find(u,parent)] = find(v,parent)
        edges = [(u,v,w,i) for i, (u,v,w) in enumerate(edges)]
        edges.sort(key = lambda e:e[2])
        def find_mst_without_this_edge(idx):
            parent = list(range(n))
            res = 0
            for i, (u, v, w, _) in enumerate(edges):
                if i == idx: continue
                if find(u, parent) != find(v, parent):
                    res += w
                    union(u, v, parent)
            root = find(0, parent)
            return res if all(find(i, parent) == root for i in range(n)) else float('inf')
        def find_mst_with_this_edge(idx):
            parent = list(range(n))
            u0, v0, w0, _ = edges[idx]
            res = w0
            union(u0,v0,parent)
            for i, (u, v, w, _) in enumerate(edges):
                if i == idx:
                    continue
                if find(u, parent) != find(v, parent):
                    res += w
                    union(u, v, parent)
            root = find(0, parent)
            return res if all(find(i, parent) == root for i in range(n)) else float('inf')
        base_mst_wgt = find_mst_without_this_edge(-1)
        cri, pcri = set(), set()
        for i in range(len(edges)):
            wgt_excl = find_mst_without_this_edge(i)
            if wgt_excl > base_mst_wgt:
                cri.add(edges[i][3])
            else:
                wgt_incl = find_mst_with_this_edge(i)
                if wgt_incl == base_mst_wgt:
                    pcri.add(edges[i][3])
        return [cri, pcri]