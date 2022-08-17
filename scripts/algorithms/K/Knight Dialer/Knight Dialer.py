class Solution:
    def knightDialer(self, n: int) -> int:
        # Sum elements of matrix modulo mod subroutine
        def sum_mat(matrix, mod):
            return sum(sum(row) % mod for row in matrix) % mod
        
        # Matrix multiplication subroutine
        def mult_mat(a, b):
            return [[sum(a[i][k]*b[k][j] for k in range(10)) for j in range(10)] for i in range(10)]
        
        # Matrix exponentiation subroutine
        def pow_mat(matrix, k, dp):
            if k not in dp:
                if k == 0:
                    dp[k] = [[(1 if i == j else 0) for j in range(10)] for i in range(10)]
                else:
                    dp[k] = pow_mat(matrix, k//2, dp)
                    dp[k] = mult_mat(dp[k], dp[k])
                    if k % 2:
                        dp[k] = mult_mat(dp[k], matrix)
            return dp[k]
       
        # Create matrix
        edges = [(1, 6), (1, 8), (2, 9), (2, 7), (3, 4), (3, 8), (4, 0), (4, 9), (6, 1), (6, 0), (6, 7)]
        matrix =  [[0 for j in range(10)] for i in range(10)]
        for i, j in edges:
            matrix[i][j] = 1
            matrix[j][i] = 1
        
		# Solve
        mod = 10**9 + 7
        return sum_mat(pow_mat(matrix, n-1, {}), mod)
