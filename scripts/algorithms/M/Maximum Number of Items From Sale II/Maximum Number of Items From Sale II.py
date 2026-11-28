# Runtime: 169 ms (Top 89.19%) | Memory: 59.70 MB (Top 24.32%)

class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        factors, prices = zip(*items)
        have = [0] * (len(items) + 1)  # have[f]: items with factor f
        for factor in factors:
            have[factor] += 1
        deals = cache(lambda factor: sum(have[factor::factor]) - 1)  # counted when an item is reached

        cheapest = min(prices)
        heap = [(price, factor) for factor, price in items if price < 2 * cheapest]
        heapify(heap)
        copies = 0
        while heap and heap[0][0] <= budget:  # the cheapest deal left is affordable
            price, factor = heappop(heap)
            pairs = min(deals(factor), budget // price)
            copies += 2 * pairs
            budget -= pairs * price
        return copies + budget // cheapest
