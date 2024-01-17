// Runtime: 55 ms (Top 98.76%) | Memory: 17.70 MB (Top 35.84%)

class Solution:
    def intersection(self, A: List[List[int]]) -> List[int]:
        return sorted([k for k,v in Counter([x for l in A for x in l]).items() if v==len(A)])
		
