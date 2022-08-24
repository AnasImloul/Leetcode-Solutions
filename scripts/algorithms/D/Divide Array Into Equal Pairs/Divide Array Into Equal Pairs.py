// Runtime: 159 ms (Top 42.07%) | Memory: 14.2 MB (Top 19.67%)
class Solution:

    def divideArray(self, nums: List[int]) -> bool:
        lena = len(nums)
        count = sum(num//2 for num in Counter(nums).values())
        return (lena/2 == count)
