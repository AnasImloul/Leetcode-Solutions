// Runtime: 151 ms (Top 99.29%) | Memory: 19.30 MB (Top 5.84%)

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        st = []
        n = len(nums)
        ans = [-1] * n
        for i in range(2*n-1, -1, -1):
            while st and st[-1] <= nums[i%n]:
                st.pop()
            if st and i < n:
                ans[i] = st[-1]
            st.append(nums[i%n])
        return ans
