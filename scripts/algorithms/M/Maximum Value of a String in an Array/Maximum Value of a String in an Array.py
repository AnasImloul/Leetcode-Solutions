# Runtime: 0 ms (Top 100.00%) | Memory: 18.90 MB (Top 98.81%)

class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        maxx = 0
        for item in strs:  
            maxx = max(maxx,int(item)) if item.isdigit() else max(maxx,len(item))
        return maxx
