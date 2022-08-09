class Solution:
    # generate all possible summation 
    def helper(self, arr):
        n = len(arr)
        #we need to keep unique elements
		#For this array (Say array nums) of size n, we have 2 ^ n subset from it (you must know some math).
#For this problem, n is not too large (n <= 20) so that we can utilize bitmask technique.
#Mask is an 32-bit integer, if i-th bit of this mask is on, it means our subset contains i-th element of nums.
#All mask values are in the range between 0b000...0000 (n 0's)  and 0b111...1111 (n 1's), so it means all masks are in the range of [0, (1 << n) - 1]
        ans = {0}  # initially, answer array contains 0 because of Empty subset
        for mask in range(1, 1 << n):
            ss = 0
            for i, val in enumerate(arr):
                if (1 << i) & mask:  # using bitmask to check whether subset contains the i-th element of arr or not
                    ss += val
            ans.add(ss)
        return list(ans)
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        n = len(nums)
      #  random.shuffle(nums)
        n_2 = n // 2
        s1, s2 = self.helper(nums[:n_2]), self.helper(nums[n_2 :])
        s1.sort()
        s2.sort()
        ans = abs(goal)

        # 2 pointers to find the answer
        i1, i2 = 0, len(s2) - 1
        while i1 < len(s1) and i2 >= 0:
            cur = s1[i1] + s2[i2]
            ans = min(ans, abs(cur - goal))
            if cur == goal:
                return 0
            elif cur > goal:
                i2 -= 1
            else:
                i1 += 1
        return ans
