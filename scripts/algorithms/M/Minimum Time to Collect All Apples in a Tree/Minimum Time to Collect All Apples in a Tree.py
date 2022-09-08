# Runtime: 1818 ms (Top 5.15%) | Memory: 87.1 MB (Top 5.14%)
class Solution:

    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        graph_map = {i: set() for i in range(n)}
        for edge in edges:
            graph_map[edge[0]].add(edge[1])
            graph_map[edge[1]].add(edge[0])

        self.result = set()
        visited = set()
        def dfs(node, path):
            visited.add(node)
            if hasApple[node]:
                temp = path + '|' + str(node)
                temp = temp.split('|')[1:]
                # print(temp)
                for i in range(1, len(temp)):
                    self.result.add((temp[i], temp[i-1]))
            for nei in graph_map[node]:
                if nei not in visited:
                    dfs(nei, path + '|' + str(node))

        dfs(0, "")
        # print(self.result)
        return len(self.result) * 2