class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        adjList=defaultdict(list)
        leaves=[]
        ct=0
        
        [#undirected graph two way using parent and node in postorder style]
        def dfs(node, parent):
            if node:
                if not node.left and not node.right:
                    leaves.append(node)
                adjList[node].append(parent)
                adjList[parent].append(node)
                dfs(node.left,node)
                dfs(node.right,node)
        
        [#construct graph and get all the leaves]
        dfs(root, None)
        
        #bfs from each leaf till we find another leaf
        for leaf in leaves:
            q=deque([(leaf,0)] )
            seen=set()
            while q:
                curr,dist = q.popleft()
                seen.add(curr)
                if dist>distance:
                    break                
                for nbr in adjList[curr]:
                    if nbr and nbr not in seen:
                        if nbr in leaves and dist+1<=distance:
                            ct+=1
                        q.append((nbr,dist+1))
        
        return ct//2