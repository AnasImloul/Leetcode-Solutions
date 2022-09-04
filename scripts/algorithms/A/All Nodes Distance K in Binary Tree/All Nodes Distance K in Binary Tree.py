# Runtime: 87 ms (Top 5.40%) | Memory: 14.2 MB (Top 98.06%)
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:

        # DFS to make the adj List
        adjList = defaultdict(list)
        def dfs(node):
            if not node:
                return

            if node.left:
                adjList[node].append(node.left)
                adjList[node.left].append(node)

            if node.right:
                adjList[node].append(node.right)
                adjList[node.right].append(node)
            dfs(node.left)
            dfs(node.right)

        dfs(root)

        # bfs to find the nodes with k distance

        q = deque([(target, 0)])
        visit = set()
        visit.add(target)
        res = []
        while q:
            for i in range(len(q)):
                node, dist = q.popleft()

                if dist == k:
                    res.append(node.val)

                if dist > k:
                    break
                for nei in adjList[node]:
                    if nei not in visit:
                        visit.add(nei)
                        q.append((nei, dist + 1))
        return res
