# Runtime: 282 ms (Top 5.10%) | Memory: 13.9 MB (Top 81.34%)
class Solution:
    def findGCD(self, nums: List[int]) -> int:
        i_min = min(nums)
        i_max = max(nums)
        greater = i_max
        while True:
            if greater % i_min == 0 and greater % i_max == 0:
                lcm = greater
                break
            greater += 1
        return int(i_min/(lcm/i_max))