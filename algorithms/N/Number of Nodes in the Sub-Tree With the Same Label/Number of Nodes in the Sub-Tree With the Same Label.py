class Solution:
    """
    we can solve this using dfs based approach
    identify the root of the tree and start a dfs from there 
    """
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        graph_map = {i: set() for i in range(n)}
        for edge in edges:
            graph_map[edge[0]].add(edge[1])
            graph_map[edge[1]].add(edge[0])
            
        result = [None for _ in range(n)]
        
        visited = set()
        def dfs(index):
            visited.add(index)
            temp = [0 for _ in range(26)]
            temp[ord(labels[index])-97]+=1
            for idx in graph_map[index]:
                if idx not in visited:
                    x = dfs(idx)
                    temp = [a + b for a, b in zip(temp, x)]
            result[index] = temp[ord(labels[index])-97]
            return temp
        
        dfs(0)
        return result
