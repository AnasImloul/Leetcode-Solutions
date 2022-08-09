class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        leng = len(coins)
        def dfs(amount, start):
            if amount == 0: return 1
            elif amount < 0: return 0
            res = 0
            for i in range(start, leng):
                res += dfs(amount - coins[i], i)
            return res
        return dfs(amount, 0)
