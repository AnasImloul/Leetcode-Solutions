// Runtime: 31 ms (Top 88.8%) | Memory: 16.50 MB (Top 52.0%)

class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        
        x = label
        mask = 0 
        while x > 1:
            x >>= 1
            mask <<= 1
            mask |= 1
            
        x = label
        res = deque()
        while x:
            res.appendleft(x)
            x >>= 1
            mask >>= 1
            x ^= mask
        return res
