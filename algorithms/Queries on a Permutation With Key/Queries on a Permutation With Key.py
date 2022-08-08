class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        perm=[i for i in range(1,m+1)]
        res=[]
        for i in queries:
            ind=perm.index(i)
            res.append(ind)
            perm=[perm.pop(ind)]+perm
        return res
