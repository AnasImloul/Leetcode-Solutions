# Runtime: 735 ms (Top 90.20%) | Memory: 19.60 MB (Top 57.84%)

class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        factors, prices = zip(*items)
        have = [0] * (max(factors) + 1)  # have[f]: items with factor f
        for factor in factors:
            have[factor] += 1
        gains = {factor: sum(have[factor::factor]) for factor in set(factors)}  # every factor-th cell is a multiple

        cheapest = min(prices)
        best = [money // cheapest for money in range(budget + 1)]  # no first copies yet: everything goes to the cheapest item
        for factor, price in items:
            if (gain := gains[factor]) > price // cheapest:  # else the same money buys as many copies of the cheapest item
                for money in range(budget, price - 1, -1):  # backwards: one first copy per item
                    best[money] = max(best[money], best[money - price] + gain)
        return best[budget]
