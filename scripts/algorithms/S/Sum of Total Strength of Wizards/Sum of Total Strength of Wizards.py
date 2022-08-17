class Solution:
    def totalStrength(self, stp: List[int]) -> int:
        st = []
        n = len(stp)
        m1 = defaultdict(lambda:-1)
        ps = [0]
        for i in range(n):
            while st and stp[st[-1]] >= stp[i]:
                st.pop()
            if st: m1[i] = st[-1]
            st.append(i)
            ps.append(ps[-1] + stp[i])
        pss = [0]
        for i in ps:
            pss.append(pss[-1] + i)
        st = []
        m2 = defaultdict(lambda:n)
        for i in range(n-1,-1,-1):
            while st and stp[st[-1]] > stp[i]:
                st.pop()
            if st: m2[i] = st[-1]
            st.append(i)

        ans = 0
        mod = 10**9 + 7
        for i in range(n):
            left = m1[i] + 1
            right = m2[i]
            p1 = (i+1-left)*(pss[right+1]-pss[i+1])
            p2 = (right-i)*(pss[i+1]- pss[left])
            ans = (ans + stp[i]*(p1 - p2)) % mod
        return ans
