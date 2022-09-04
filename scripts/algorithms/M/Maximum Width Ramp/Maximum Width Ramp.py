# Runtime: 635 ms (Top 30.72%) | Memory: 21.1 MB (Top 46.08%)
class Solution:
    def maxWidthRamp(self, nums: List[int]):
        st=[]
        n=len(nums)
        for i in range(n):
            if len(st)==0 or nums[st[-1]]>=nums[i]:
                st.append(i)
        print(st)
        max_idx=-1
        for j in range(n-1,-1,-1):
            while len(st) and nums[st[-1]]<=nums[j]:
                prev=st.pop()
                max_idx=max(max_idx,j-prev)

        return max_idx
