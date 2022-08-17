class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        primes = set()
        for i in range(2,n+1):
            if all(i%p != 0 for p in primes):
                primes.add(i)
        M = 10**9 + 7
        def fact(k):
            res = 1
            for i in range(2,k+1):
                res = (res*i)%M
            return res
        return fact(len(primes))*fact(n-len(primes))%M