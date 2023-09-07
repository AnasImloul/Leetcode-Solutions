# Runtime: 306 ms (Top 74.5%) | Memory: 25.12 MB (Top 36.8%)

class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        def f(x):
            if (veganFriendly == 1 and x[2] == 1 and x[3] <= maxPrice and x[4] <= maxDistance) or (veganFriendly == 0 and x[3] <= maxPrice and x[4] <= maxDistance):
                return True
            else:
                return False
        y = list(filter(f,restaurants))
        y.sort(key=lambda a:a[0],reverse=True)
        y.sort(key=lambda a:a[1],reverse=True)
        return [i[0] for i in y]