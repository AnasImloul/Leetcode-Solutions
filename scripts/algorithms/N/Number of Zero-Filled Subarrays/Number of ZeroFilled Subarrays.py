class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:       
        number_of_zerosubs = 0
        counter = 0
        for i in nums:
            if not i:
                counter += 1
            elif counter:
                number_of_zerosubs += sum(range(1, counter+1))
                counter = 0
        if not nums[-1]:
            number_of_zerosubs += sum(range(1, counter+1))
        return number_of_zerosubs