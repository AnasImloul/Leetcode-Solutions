class Solution:
    def countBits(self, n: int) -> List[int]:
        # We know that all exponential values of two have 1 bit turned on, the rest are turned off.
        # Now, we can find a relation with following numbers after 2, where the numbers can be decomposed 
        # into smaller numbers where we already have found the # of 1s, for example.
        # F(3) = F(2^1) + F(1) = 1 + 1 = 3
        # F(4) = F(2^2) + F(0) = 1 + 0. ( Even thought we havent defined F(4) = F(2^2), by the previous established)
        # comment, we can safely say that all F(2^X) has only 1 bit so thats where F(4) would be = 1
        # F(5) = F(2^2) + F(1) = 1 + 1 = 2
        # F(6) = F(2^2) + F(2) = F(4) + F(2) = 1 + 1
        # The relation countinues for all following numbers
        
        # This solution is O(N)
        # With O(1) extra space ( considering dp is the returned answer )
        
        dp = [0]
		
        for i in range(1, n + 1):
            exponent = int(math.log(i) / math.log(2))
            num = 2**exponent
            decimal = i % (num)
            if num == i:
                dp.append(1)
            else:
                dp.append(dp[num] + dp[decimal])
        return(dp)
