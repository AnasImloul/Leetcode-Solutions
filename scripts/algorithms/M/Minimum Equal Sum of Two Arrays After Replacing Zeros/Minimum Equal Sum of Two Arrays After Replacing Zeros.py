# Runtime: 733 ms (Top 96.77%) | Memory: 35.00 MB (Top 100.00%)

class Solution:
    def minSum(self, nums1, nums2):
        sum1, cnt1 = 0, 0
        sum2, cnt2 = 0, 0

        for ele in nums1:
            if ele != 0:
                sum1 += ele
            else:
                sum1 += 1
                cnt1 += 1

        for ele in nums2:
            if ele != 0:
                sum2 += ele
            else:
                sum2 += 1
                cnt2 += 1

        if sum1 == sum2:
            return sum1
        elif sum1 > sum2:
            if cnt2 == 0:
                return -1
            return sum1

        if cnt1 == 0:
            return -1
        return sum2
