// Runtime: 5781 ms (Top 22.88%) | Memory: 36.00 MB (Top 13.56%)

class Fenwick:
    """Fenwick tree aka binary indexed tree"""
    def __init__(self, n):
        self.nums = [0]*(n+1)
        
    def sum(self, k): 
        ans = 0
        while k: 
            ans += self.nums[k]
            k &= k-1
        return ans 
    
    def add(self, i, x): 
        i += 1
        while i < len(self.nums): 
            self.nums[i] += x
            i += i & -i


class Solution:
    def createSortedArray(self, instructions: List[int]) -> int:
        ans = 0
        fen = Fenwick(10**5)
        freq = {} # frequency of each instructions
        for i, x in enumerate(instructions): 
            less = fen.sum(x)
            more = i - freq.get(x, 0) - less
            ans += min(less, more)
            fen.add(x, 1)
            freq[x] = 1 + freq.get(x, 0)
        return ans % 1_000_000_007
