class Solution:
    def countPrimes(self, n: int) -> int:
        # Prerequisite:
        # What is prime number. What are they just the starting. 
        
        truth = [True]*n # making a list of lenght n. And keep all the values as True.
        if n<2: # as 0 & 1 are not prime numbers. 
            return 0
        truth[0], truth[1] = False, False #as we added True in the truth list. So will make false for ) & 1 as they are not prime numbers.
        
        i=2 # As we know 0 & 1 are not prime.
        while i*i<n: # why we are doing it as i*i here is bcz lets say 5*2 = 10 is divisble by 2 as well as 5 so if 10 is already removed why to traverse a value which is already travered once. so in case of n=5 - 5<5. CONCLUSION : i<sqrt(n)
#why we are running the loop till n is bcz question says " prime numbers that are strictly less than n".
            if truth[i] == True:
                for j in range(i*i,n,i): # if we have mutiple of a number in the range of n, we have to remove them as they can be prime. i.e 2 is prime, but its multiple in n = 10 are 4,6,8 they cant be prime. So we will make them false(means not a prime).
                    truth[j]=False
            i += 1 # increasing our iterator.
        return truth.count(True) # will count true value 
        
