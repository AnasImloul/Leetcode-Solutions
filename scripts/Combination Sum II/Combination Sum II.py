class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ds=[]
        res=[]
        candidates.sort()
        n=len(candidates)
        comb(0,n,candidates,target,ds,res)
        return res
def comb(ind,n,candidates,target,ds,res):
    if target==0:
        res.append(ds.copy())
        return
    for i in range(ind,n):
        if i>ind and candidates[i]==candidates[i-1]:
            continue
        if candidates[i]>target:
            break
        ds.append(candidates[i])
        comb(i+1,n,candidates,target-candidates[i],ds,res)
        ds.pop()