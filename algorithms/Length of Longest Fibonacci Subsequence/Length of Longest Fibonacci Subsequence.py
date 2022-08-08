class Solution(object): #DP. Time Complexity: O(N^2), Space Complexity: O(NlogM), M = max(A)
    def lenLongestFibSubseq(self, A):
        index = {Ai: i for i, Ai in enumerate(A)}
        dp = collections.defaultdict(lambda: 2)
        ans = 0
        for k, Ak in enumerate(A): #Following IJK idiom here
            for j in range(k-1,0,-1):            
                i = index.get(Ak - A[j], None)
                if Ak - A[j] >= A[j]: break #Pruning for illegal Ai
                if i is not None and i < j:
                    cur_len = dp[j, k] = dp[i, j] + 1
                    ans = max(ans, cur_len)
        
        return ans # ans is either 0 or >=3 for SURE

