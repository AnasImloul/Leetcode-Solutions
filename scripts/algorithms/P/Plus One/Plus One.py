// Runtime: 33 ms (Top 85.76%) | Memory: 16.50 MB (Top 60.81%)

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:

        for i in range(len(digits)-1, -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] = digits[i] + 1
                return digits
        return [1] + digits 

        
