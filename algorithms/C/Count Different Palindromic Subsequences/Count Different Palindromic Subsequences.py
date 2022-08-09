class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        
        N = len(s)
        mod = 10**9 + 7
        memo = {}
        
        def backTrack(start,end):
            
            if start >= N or end < 0: return 0
            
            key = (start,end) 
            
            if key in memo: return memo[key]
            
            strn = s[start:end+1]

            memo[key] = 0

            for char in "abcd":
                if not char in strn: continue
                i = start + strn.index(char)
                j = start + strn.rindex(char)
                memo[key] += backTrack(i+1,j-1) + 2 if i != j else 1
            
            memo[key] %= mod
            
            return memo[key]
        
        return backTrack(0,N-1)

