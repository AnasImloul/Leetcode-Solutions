class Solution:
    def canDistribute(self, nums: List[int], quantity: List[int]) -> bool:
        freq = {}
        for x in nums: freq[x] = 1 + freq.get(x, 0)
        
        vals = sorted(freq.values(), reverse=True)
        quantity.sort(reverse=True) # pruning - large values first  
        
        def fn(i): 
            """Return True if possible to distribute quantity[i:] to remaining."""
            if i == len(quantity): return True 
            seen = set()
            for k in range(len(vals)): 
                if vals[k] >= quantity[i] and vals[k] not in seen: 
                    seen.add(vals[k]) # pruning - unqiue values 
                    vals[k] -= quantity[i]
                    if fn(i+1): return True 
                    vals[k] += quantity[i] # backtracking
                    
        return fn(0)