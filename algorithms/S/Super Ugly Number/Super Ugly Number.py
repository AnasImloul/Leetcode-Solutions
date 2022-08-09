class Solution:
def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
    prime_nums = len(primes)
    index = [1]*prime_nums
    ret = [1]*(n+1)
    for i in range(2,n+1):
        ret[i] = min(primes[j]*ret[index[j]] for j in range(prime_nums))
        for k in range(prime_nums):
            if ret[i] == primes[k]*ret[index[k]]:
                index[k]+= 1
    
    return ret[-1]
