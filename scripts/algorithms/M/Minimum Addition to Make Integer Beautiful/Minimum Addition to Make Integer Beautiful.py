# Runtime: 0 ms (Top 100.00%) | Memory: 19.10 MB (Top 86.78%)

class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:

        sm = lambda n: sum(map(int,list(str(n))))

        zeros, diff = 10, 0                     #  Ex: n = 5617     ; target = 7

        while sm(n + diff) > target:            #   n    zeros   diff  n+diff  sm(n+diff)
                                                # -----  –––––  –––––  ––––––  –––––––––  
            diff = zeros - n%zeros              # 5617     10      3    5620     13  
                                                # 5617    100     83    5700     12
            zeros*= 10                          # 5617   1000    383    6000      6  <-- less than target
                                                #                 |
        return diff                             #               answer
