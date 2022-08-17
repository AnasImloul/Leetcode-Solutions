
class Solution:
    def intersection(self, A: List[List[int]]) -> List[int]:
        return sorted([k for k,v in Counter([x for l in A for x in l]).items() if v==len(A)])
		
