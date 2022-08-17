class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        isPrime = [True] * 33
        isPrime[0], isPrime[1] = False, False
        for i in range(33):
            if isPrime[i]:
                for j in range(2, 1 + 32 // i):
                    isPrime[i * j] = False
        ctr = 0
        for i in range(left, right + 1):
            curr = "{:b}".format(i).count("1")
            if isPrime[curr]:
                ctr += 1
        return ctr
