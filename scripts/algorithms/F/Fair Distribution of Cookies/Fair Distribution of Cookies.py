class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        ans = float('inf')
        fair = [0]*k
        def rec(i):
            nonlocal ans,fair
            if i == len(cookies):
                ans = min(ans,max(fair))
                return
			# Bounding condition to stop a branch if unfairness already exceeds current optimal soltution
			if ans <= max(fair):
                return
            for j in range(k):
                fair[j] += cookies[i]
                rec(i+1)
                fair[j] -= cookies[i]
        rec(0)
        return ans
