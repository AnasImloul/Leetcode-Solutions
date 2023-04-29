class Solution:
    def isUgly(self, n: int) -> bool:
        if n == 0:
            return False
        res=[2, 3, 5]
        while n!= 1:
            for i in res:
               if n%i==0:
                   n=n//i
                   break
            else:
                return False
        return True