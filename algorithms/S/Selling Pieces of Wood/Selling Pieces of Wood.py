class Solution:
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        price = {(dimension_price[0], dimension_price[1]): dimension_price[2] for dimension_price in prices}
        DP = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]
        
        def solve(h: int, v: int) -> int:
            if DP[h][v] != -1:
                return DP[i][j]
            
            ans = price.get((h, v), 0)
            
            for i in range(1, 1 + h // 2):
                ans = max(ans, (DP[i][v] if DP[i][v] != -1 else solve(i, v)) + (DP[h - i][v] if DP[h - i][v] != -1 else solve(h - i, v)))
            
            for j in range(1, 1 + v // 2):
                ans = max(ans, (DP[h][j] if DP[h][j] != -1 else solve(h, j)) + (DP[h][v - j] if DP[h][v - j] != -1 else solve(h, v - j)))
            
            DP[h][v] = ans
            
            return ans
        
        return solve(m, n)
