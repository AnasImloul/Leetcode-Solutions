# Runtime: 1072 ms (Top 44.44%) | Memory: 42.9 MB (Top 86.75%)
class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:

        from itertools import combinations
        mydict=defaultdict(int)
        ans=0

        for a,b in combinations(nums,2):
            mydict[a*b]+=1

        for i,j in mydict.items():
            if j>1:
                ans+=(j*(j-1)//2)*8

        return ans