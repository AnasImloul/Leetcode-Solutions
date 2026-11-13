# Runtime: 67 ms (Top 27.52%) | Memory: 19.00 MB (Top 94.50%)

class Solution:
    def smallestValue(self, n):

        prev, ans = n, 0

        while not n%2:                  # 2 is the unique even prime
                ans += 2
                n//= 2

        for i in range(3,n+1,2):        #  <–– prune even divisors...
                while not n%i:
                    ans += i
                    n//= i

        return self.smallestValue(ans) if ans != prev else ans
