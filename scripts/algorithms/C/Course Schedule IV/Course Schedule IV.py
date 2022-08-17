class Solution:
    """
    one approach I can think of is, given a graph, 
    the query[a, b] will be true if there exists a path from a to b in the graph
    else a will not be a prerequisite of b
    but this approach may not scale as the # of queries will increase
    """
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        graph = {node: set() for node in range(numCourses)}
        for pre in prerequisites:
            graph[pre[0]].add(pre[1])
        
        def path(cur_node, node_b):
            if cur_node == node_b:
                return True
            for neighbor in graph[cur_node]:
                if path(neighbor, node_b):
                    return True
            return False
            
        ans = []
        for query in queries:
            # see if there is a path from query[0] to query[1]
            ans.append(path(query[0], query[1]))
        return ans
