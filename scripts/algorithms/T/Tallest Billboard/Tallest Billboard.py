# Runtime: 760 ms (Top 68.15%) | Memory: 14.5 MB (Top 56.05%)

class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        dp = collections.defaultdict(int)
        dp[0] = 0
        for x in rods:
            nxt = dp.copy()
            for d, y in dp.items():
                # init state
                # ------|----- d -----| # tall side
                # - y --| # low side

                # put x to tall side
                # ------|----- d -----|---- x --|
                # - y --|
                nxt[d + x] = max(nxt.get(x + d, 0), y)

                nxt[abs(d - x)] = max(nxt.get(abs(d - x), 0), y + min(d, x))
            dp = nxt
        return dp[0]