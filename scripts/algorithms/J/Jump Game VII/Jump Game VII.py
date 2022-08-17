class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
		# dp[i] represents whether i is reachable
        dp = [False for _ in s]
        dp[0] = True

        for i in range(1, len(s)):
            if s[i] == "1":
                continue

			# iterate through the solutions in range [i - maxJump, i - minJump]
			# and if any previous spot in range is reachable, then i is also reachable
            window_start = max(0, i - maxJump)
            window_end = i - minJump
            for j in range(window_start, window_end + 1):
                if dp[j]:
                    dp[i] = True
                    break
        
        return dp[-1]       

