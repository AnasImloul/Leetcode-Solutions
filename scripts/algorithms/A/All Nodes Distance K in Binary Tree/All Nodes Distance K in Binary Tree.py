// Runtime: 38 ms (Top 85.62%) | Memory: 17.70 MB (Top 14.33%)

class Solution:
    def distanceK(self, root, target, K):
        # Step 1: Build adjacency list graph
        graph = {}
        self.buildGraph(root, None, graph)

        # Step 2: Perform BFS from the target node
        queue = [(target, 0)]
        visited = set([target])
        result = []
        
        while queue:
            node, distance = queue.pop(0)
            
            if distance == K:
                result.append(node.val)
                
            if distance > K:
                break
            
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, distance + 1))
        
        return result
    
    def buildGraph(self, node, parent, graph):
        if not node:
            return
        
        if node not in graph:
            graph[node] = []
            
        if parent:
            graph[node].append(parent)
            graph[parent].append(node)
            
        self.buildGraph(node.left, node, graph)
        self.buildGraph(node.right, node, graph)

