// Runtime: 77 ms (Top 87.66%) | Memory: 17.40 MB (Top 8.01%)

class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        count = 0
        while num1 != 0 and num2 != 0:
            if num1 >= num2:
                num1 -= num2
            else:
                num2 -= num1
            count +=1
        return count
