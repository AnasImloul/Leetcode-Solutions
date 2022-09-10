# Runtime: 62 ms (Top 23.33%) | Memory: 13.9 MB (Top 12.32%)
class Solution(object):
    def plusOne(self, digits):
        for i in range(len(digits)-1, -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
        return [1] + digits