class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        sum = 0
        root = num**0.5  
        if num ==1:
            return False
        for i in range(2,int(root)+1):
            if num%i== 0:
                sum +=(num//i)+i
        return sum+1 == num
