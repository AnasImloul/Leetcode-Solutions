# Runtime: 2044 ms (Top 58.33%) | Memory: 167.00 MB (Top 51.39%)

class Solution:
    def maximumPoints(self, edges: List[List[int]], coins: List[int], k: int) -> int:

        # Creating the adjacency list
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # 2D array to store results for each node for different values of halved count
        dp = [[-1 for _ in range(15)] for _ in range(len(coins))]

        # Post-order traversal to compute maximum points using Bottom-Up DP
        def dfs2(node, parent, halved):
            # Base condition
            if halved >= 15:
                return 0

            # If value is already computed, return it
            if dp[node][halved] != -1:
                return dp[node][halved]

            # Calculate score if we use Method 1
            method1_score = (coins[node] >> halved) - k
            # Calculate score if we use Method 2
            method2_score = (coins[node] >> (halved + 1))

            # Calculate children's contribution for both methods
            for child in adj[node]:
                if child != parent:
                    method1_score += dfs2(child, node, halved)
                    method2_score += dfs2(child, node, halved + 1)

            # Store the result in dp array
            dp[node][halved] = max(method1_score, method2_score)

            return dp[node][halved]

        # Start from root node without any halving
        return dfs2(0, -1, 0)
