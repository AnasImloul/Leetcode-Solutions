// Runtime: 150 ms (Top 93.95%) | Memory: 18.00 MB (Top 86.53%)

class Solution:
    def findErrorNums(self, nums):
        n = len(nums)
        v = [0] * (n + 1)
        missing, duplicate = 0, 0

        for num in nums:
            v[num] += 1

        for i in range(1, len(v)):
            if v[i] == 2:
                duplicate = i
            if v[i] == 0:
                missing = i

        return [duplicate, missing]


