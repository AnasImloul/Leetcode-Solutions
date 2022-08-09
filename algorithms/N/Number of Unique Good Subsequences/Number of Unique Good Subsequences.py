class Solution:
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        
        
        # zero_as_last: the count of S0, good sequence ending in 0
        # one_as_last : the count of S1: good sequence ending in 1
        # zero_exist:   existence flag of 0 in given binary
        
        dp = {"zero_as_last": 0, "one_as_last": 0, "zero_exist": 0}
        
        for bit in map(int, binary):
            
            if bit:
                # current good = ( S0 concate with 1 ) + ( S1 concate with 1 ) + 1 alone
                # + "1" is allowed because leading 1 is valid by description
                dp["one_as_last"] = dp["zero_as_last"] + dp["one_as_last"] + 1
            
            else:
                # current good = ( S0 concate with 0 ) + ( S1 concate with 0 ) 
                # + "0" is NOT allowed because leading 0 is invalid by description
                dp["zero_as_last"] = dp["zero_as_last"] + dp["one_as_last"]
            
            # check the existence of 0
            dp["zero_exist"] |= (1-bit)
        
        
        return sum( dp.values() ) % ( 10**9 + 7 )
