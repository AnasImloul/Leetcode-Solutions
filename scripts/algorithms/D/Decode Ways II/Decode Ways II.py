# Runtime: 180 ms (Top 97.4%) | Memory: 21.20 MB (Top 53.7%)

class Solution:
    def numDecodings(self, s: str):
        if s[0] == '0': return 0
        cMap = {'0':0, '*': 9, '**': 15, '1*': 9, '2*': 6} #{char(s) : multiplier} mapping
        for i in range(1, 27): cMap[str(i)] = 1
        for i in range(0, 7): cMap['*'+str(i)] = 2
        for i in range(7, 10): cMap['*'+str(i)] = 1
        
        dp = [0]*(len(s)+1)
        dp[0], dp[-1] = cMap[s[0]] , 1
        
        for i in range(1, len(s)):
            dp[i] += (cMap[s[i]]*dp[i-1] + cMap.get(s[i-1:i+1],0)*dp[i-2])%(10**9 + 7)
            if not dp[i]: return 0
            
        return dp[-2]