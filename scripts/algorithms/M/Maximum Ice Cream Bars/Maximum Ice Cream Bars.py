class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        i= 0
        for price in costs:
            if price<= coins:
                i+= 1
                coins-= price
            else:
                break
        return i