// Runtime: 1128 ms (Top 98.57%) | Memory: 75.00 MB (Top 57.14%)

class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
                                                                  
        pref = list(accumulate(candiesCount, initial = 0))         
        
        return [pref[candy]//cap <= day < pref[candy + 1]
                           for candy, day, cap in queries]
