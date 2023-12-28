// Runtime: 584 ms (Top 98.04%) | Memory: 28.70 MB (Top 26.47%)

from collections import Counter, defaultdict

class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        quantity.sort(reverse=True)
        freqCounts = defaultdict(int, Counter(Counter(nums).values()))
        def backtrack(i: int = 0) -> bool:
            if i == len(quantity):
                return True
            
            for freq, count in list(freqCounts.items()):
                if freq >= quantity[i] and count > 0:
                    freqCounts[freq] -= 1
                    freqCounts[freq - quantity[i]] += 1
                    if backtrack(i + 1):
                        return True
                    freqCounts[freq] += 1
                    freqCounts[freq - quantity[i]] -= 1
            
            return False
        
        return backtrack()
