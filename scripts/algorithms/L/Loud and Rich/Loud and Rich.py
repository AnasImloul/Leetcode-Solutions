class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        length = len(quiet)
        arr = [i for i in range(length)]
        indegree = [0 for _ in range(length)]
        graph = collections.defaultdict(list)
        dq = collections.deque([])
        
        for a, b in richer:
            # Note that the graph is uni-directional
            graph[a].append(b)
            indegree[b] += 1

        for i in range(length):
            if not indegree[i]: 
                dq.append(i)
    
        while dq:
            node = dq.popleft()
            
            for vertex in graph[node]:
                indegree[vertex] -= 1
                if quiet[arr[node]] < quiet[arr[vertex]]:
                    arr[vertex] = arr[node]
                if not indegree[vertex]:
                    dq.append(vertex)
        return arr
