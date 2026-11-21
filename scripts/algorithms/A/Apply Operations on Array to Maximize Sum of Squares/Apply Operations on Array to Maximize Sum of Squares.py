# Runtime: 1273 ms (Top 86.28%) | Memory: 84.20 MB (Top 5.38%)

class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:

        size = max(nums).bit_length()
        f = lambda x: list((bin(x)[2:].rjust(size, '0')))

        mat = list(zip(*(map(sorted,zip(*map(f, nums))))))

        return sum([pow(int(''.join(m),2),2) for m in mat[-k:]]) %1_000_000_007
