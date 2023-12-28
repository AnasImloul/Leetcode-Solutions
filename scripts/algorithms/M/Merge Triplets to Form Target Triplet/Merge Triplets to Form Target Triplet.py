// Runtime: 2191 ms (Top 5.08%) | Memory: 62.60 MB (Top 7.94%)

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        
        a, b, c = 0, 0, 0
        for i, (x, y, z) in enumerate(triplets):
                if not(  x > target[0] or y > target[1] or z > target[2]):
                     a, b, c = max(a, x), max(b, y), max(c, z)
                        
        return [a, b, c] == target
            
