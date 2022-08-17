class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        # ignore restricted node
        # bfs from 0
        
        # O(E), EDITED: the time complexity here is wrong, plz see my comment
        adj_dict = collections.defaultdict(list)
        for u, v in edges:
            if u in restricted or v in restricted:  # EDITED: not O(1)
                continue
            adj_dict[u].append(v)
            adj_dict[v].append(u)
        
        # O(V + E)
        queue = collections.deque([0])
        visited = {0}
        while queue:
            cur = queue.popleft()
            for neighbor in adj_dict[cur]:
                if neighbor in visited:
                    continue
                visited.add(neighbor)
                queue.append(neighbor)

        return len(visited)
