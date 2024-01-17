// Runtime: 35 ms (Top 84.03%) | Memory: 17.30 MB (Top 39.5%)

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        loc = {x: i for i, x in enumerate(row)}
        ans = 0
        for i in range(0, len(row), 2): 
            p = row[i] - 1 if row[i]&1 else row[i]+1
            if row[i+1] != p: 
                ans += 1
                ii = loc[p]
                loc[row[i+1]], loc[row[ii]] = loc[row[ii]], loc[row[i+1]] # swap mappings
                row[i+1], row[ii] = row[ii], row[i+1] # swap values 
        return ans 
