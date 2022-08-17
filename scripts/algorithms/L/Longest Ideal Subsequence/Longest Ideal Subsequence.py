class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        DP = [0 for _ in range(26)]
        ans = 1
        
        for ch in s:
            i = ord(ch) - ord('a')
            DP[i] = DP[i] + 1
            
            for j in range(max(0, i - k), min(25, i + k) + 1):
                if j != i:
                    DP[i] = max(DP[i], DP[j] + 1)
            
            ans = max(ans, DP[i])
        
        return ans
