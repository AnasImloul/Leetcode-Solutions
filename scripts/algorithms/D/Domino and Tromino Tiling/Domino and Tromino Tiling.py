# Runtime: 65 ms (Top 39.49%) | Memory: 13.8 MB (Top 98.53%)
class Solution(object):
    def numTilings(self, n):
        """
        :type n: int
        :rtype: int
        """
        '''
        f(n) = ways to fill a full board of size n
        p(n) = ways to fill a full board of size n + 1 square (up or down) aka. partial
        i) f(n) = f(n-1) + f(n-2) + 2*p(n-2)
        ii) p(n) = f(n-1) + p(n-1)
        By substituting ii) in i)
        iii) f(n) = f(n-1) + f(n-2) + 2*f(n-3) + 2*p(n-3)
        By substituting i) in iii)
        iv) f(n) = f(n-1) + f(n-2) + 2*f(n-3) + f(n-1) - f(n-2) - f(n-3)
        Simplifying iv in terms of f()
        v) f(n) = 2*f(n-1) + f(n-3)

        Recurrence Equation from above:
        f(n) = 0 when n=0;
             = 1 when n=1
             = 2 when n=2
             = 5 when n=3
             = 2*f(n-1) + f(n-3) when n>3
        '''
        #base cases
        table = [0,1,2,5]
        if n<4:
            return table[n]
        v3 = 1
        v2 = 2
        v1 = 5
        for i in range(4,n+1):
            v = 2*v1 + v3
            v3,v2,v1=v2,v1,v
        return v%(10**9+7)