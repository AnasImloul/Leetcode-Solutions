// Runtime: 32 ms (Top 99.21%) | Memory: 17.20 MB (Top 18.9%)

class Solution:
    def isPrime(self, num):
        from math import sqrt
        if num < 2 or num % 2 == 0:
            return num == 2
        for i in range(3, int(sqrt(num)) + 1, 2):
            if num % i == 0:
                return False
        return True

    def primePalindrome(self, n: int) -> int:
        if 8 <= n <= 11:
            return 11
        if len(str(n)) % 2 == 0:
            limit = pow(10, len(str(n)) // 2)
        else:
            n_string = str(n)
            limit = n_string[:len(str(n)) // 2 + 1]
        for i in range(int(limit), 20000):
            y = int(str(i) + str(i)[:-1][::-1])
            if y >= n and self.isPrime(y):
                return y
