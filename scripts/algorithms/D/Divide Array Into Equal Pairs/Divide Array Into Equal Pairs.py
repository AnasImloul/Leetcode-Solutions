class Solution:

    def divideArray(self, nums: List[int]) -> bool:
        lena = len(nums)
        count = sum(num//2 for num in Counter(nums).values())
        return (lena/2 == count)
        
