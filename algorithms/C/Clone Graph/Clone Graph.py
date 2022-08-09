    def cloneGraph(self, node: 'Node') -> 'Node':
        
        if node == None:
            return None
        
        new_node = Node(node.val, [])
        
        visited = set()
        
        q = [[node, new_node]]
        visited.add(node.val)
        
        adj_map = {}
        
        adj_map[node] = new_node
        
        while len(q) != 0:
            
            curr = q.pop(0)
            
            
            for n in curr[0].neighbors:
                
                # if n.val not in visited:
                if n not in adj_map and n is not None:
                    new = Node(n.val, [])
                    curr[1].neighbors.append(new)
                    adj_map[n] = new
                else:
                    curr[1].neighbors.append(adj_map[n])
                    
                if n.val not in visited:
                    q.append([n, adj_map[n]])
                    visited.add(n.val) 
        
        
        return new_node

