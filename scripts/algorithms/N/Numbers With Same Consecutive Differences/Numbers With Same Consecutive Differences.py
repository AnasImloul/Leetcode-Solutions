class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        # initialize the cache with all the valid numbers of length 1
        # cache is a list of tuple (number, digit at units place)
        cache = [(0, 0), (1, 1), (2, 2), (3, 3), (4, 4), (5, 5), (6, 6), (7, 7), (8, 8), (9, 9)]
        cacheTemp = []
        
        # each iteration will store all the valid numbers of length 2 to n in cache
        for i in range(2, n + 1):
            # loop through the cache from the previous iteration
            for j in cache:
                if k == 0:
                    if j[0] != 0:
                        cacheTemp.append((j[0] * 10 + j[1], j[1]))
                elif j[1] == 0 and i == 2:
                    continue
                elif j[1] <= k - 1:
                    if j[1] < 10 - k:
                        cacheTemp.append((j[0] * 10 + j[1] + k, j[1] + k))
                elif j[1] >= 10 - k:
                    if j[1] > k - 1:
                        cacheTemp.append((j[0] * 10 + j[1] - k, j[1] - k))
                else:
                    cacheTemp.append((j[0] * 10 + j[1] - k, j[1] - k))
                    cacheTemp.append((j[0] * 10 + j[1] + k, j[1] + k))
            cache = cacheTemp   # store the list of valid integers of length i in cache
            cacheTemp = []  # empty the temporary list
        
        res = []
        for i in cache:
            res.append(i[0])
        
        return res
        
