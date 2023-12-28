// Runtime: 576 ms (Top 97.83%) | Memory: 23.00 MB (Top 5.22%)

class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        cur_max = 0
        coins.sort()
      
        for coin in coins:
            if coin == 1:
                cur_max += 1
            elif coin <= cur_max+1:
                cur_max += coin
            else: #coin > cur_max + 1
                break
        
        return cur_max+1
