# Runtime: 450 ms (Top 49.65%) | Memory: 14.6 MB (Top 82.17%)
class Solution:
    def balancedString(self, s):
        count = collections.Counter(s)
        res = n = len(s)
        if all(n/4==count[char] for char in 'QWER'):
            return 0
        left = 0
        for right, char in enumerate(s):
            # replace char whose index==right to check if it is balanced
            count[char] -= 1
            # if it is balanced, window shrinks to get the smallest length of window
            while left <= right and all(n / 4 >= count[char] for char in 'QWER'):
                res = min(res, right - left + 1)
                count[s[left]] =count[s[left]]+ 1
                left += 1
        return res