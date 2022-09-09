# Runtime: 164 ms (Top 43.73%) | Memory: 14 MB (Top 84.10%)
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        def dfs(price, special, needs, memo = {}):
            if tuple(needs) in memo:
                return memo[tuple(needs)]
            res = [sum([p * need for p, need in zip(price, needs)])] # don't use any offer
            for offer in special:
                # check if can apply the offer
                new_needs = []
                for offer_items, need in zip(offer[:-1], needs):
                    new_needs.append(need - offer_items)
                if min(new_needs) < 0:
                    continue
                # Check if without the offer is better
                value = 0
                for p, offer_items in zip(price, offer[:-1]):
                    value += p * offer_items
                if value < offer[-1]:
                    continue
                # Valid Case
                res.append(dfs(price, special, new_needs, memo) + offer[-1])
            memo[tuple(needs)] = min(res)
            return min(res)
        return dfs(price, special, needs)