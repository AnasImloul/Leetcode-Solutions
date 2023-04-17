class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
        dp = {}
        return (self.backtrack(target, types, 0, 0, dp))

    def backtrack(self, target, types, i, sm, dp):
        if((i, sm) in dp):
            return dp[(i, sm)]
        if(sm>target):
            return 0
        if(sm==target):
            return 1
        if(i==len(types)):
            return 0
        
        ans = 0
        for j in range(types[i][0]+1):
            ans = (ans + self.backtrack(target, types, i+1, sm + j*types[i][1], dp))%1000000007
        dp[(i, sm)] = ans
        return dp[(i, sm)]