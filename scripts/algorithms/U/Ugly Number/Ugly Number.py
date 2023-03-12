class Solution:
    def isUgly(self, n: int) -> bool:
        
        prime = [2, 3, 5] # prime factors list provided in question againt which we have to check the provided number. 
        
        if n == 0: # as we dont have factors for 0
            return False 
        
        for p in prime: # traversing prime numbers from given prime number list.
            while n % p == 0: # here well check if the number is having the factor or not. For instance 6%2==0 is true implies 2 is a factor of 6.
                n //= p # num = num//p # in this well be having 3(6/2), 1(3/3). Doing this division to update our number
        return n == 1 # at last well always have 1, if the number would have factors from the provided list 