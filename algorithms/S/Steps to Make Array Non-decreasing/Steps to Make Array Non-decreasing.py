class Solution:
    def totalSteps(self, nums: List[int]) -> int:
        st = []
        ans = 0
        for i in nums:
            t = 0
            while st and st[-1][0] <= i:
                t = max(t, st.pop()[1])
            x = 0 
            if st: 
                x = t+1 
            st.append([i, x])
            ans = max(ans, x)
        return ans
