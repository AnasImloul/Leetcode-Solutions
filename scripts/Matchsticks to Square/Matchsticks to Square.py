class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        target,m=divmod(sum(matchsticks),4)
        if m:return False
        targetLst=[0]*4
        length=len(matchsticks)
        matchsticks.sort(reverse=True)
        def bt(i):
            if i==length:
                return len(set(targetLst))==1
            for j in range(4):
                if matchsticks[i]+targetLst[j]>target:
                    continue
                targetLst[j]+=matchsticks[i]
                if bt(i+1):
                    return True
                targetLst[j]-=matchsticks[i]
                if not targetLst[j]:break
            return False
        return matchsticks[0]<=target and bt(0)
