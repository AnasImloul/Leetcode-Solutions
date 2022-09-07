# Runtime: 52 ms (Top 38.18%) | Memory: 13.8 MB (Top 55.89%)
class Solution:
    def areNumbersAscending(self, s):
        nums = re.findall(r'\d+', s)
        return nums == sorted(set(nums), key=int)