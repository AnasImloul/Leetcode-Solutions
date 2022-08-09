class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        n_digits = len(str(n))
        
        next_max = {
            1: [1],
            2: [22],
            3: [122, 333],
            4: [1333, 4444],
            5: [14444, 22333, 55555],
            6: [122333, 224444, 666666, 155555],
            7: [1224444, 2255555, 3334444, 1666666, 7777777]
                }
        
        if n >= int(str(n_digits) * n_digits):
            n_digits += 1
            return min(next_max[n_digits])
        
        ans = float('inf')
        for num in sorted(next_max[n_digits]):      
            cands = set(permutations(str(num)))
            cands = sorted(map(lambda x: int("".join(x)), cands))
        
            loc = bisect.bisect(cands, n)
            if loc < len(cands):           
                ans = min(ans, cands[loc])
        
        return ans
