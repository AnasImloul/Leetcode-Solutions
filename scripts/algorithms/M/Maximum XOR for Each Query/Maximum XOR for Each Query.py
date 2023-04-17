class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        m,prefix_xor = 2**maximumBit - 1 , list(accumulate(nums,xor))[::-1]
        return (i^m for i in prefix_xor)
        
        """
          2    3    4    7  ( Given )
        010  011  100  111  (given in binary)
        010  001  101  010  (since constrain is high && we have to repeatively calculate xor
                            we should use prefix-xor)
       ^  k    k    k    k  (k'th val to xor to get all set bit i.e 111)
        111  111  111  111  ( this is result and we have to find val of k for each query)
    
        
        NOTE: i ^ k = res, then i ^ res = k
        So take the prefix-xor and xor every ele with all set bit.
        all set-bit = pow(2,maximumBit) - 1
        prefix-xor = accumulate(nums,xor)
        
        make sure to use prefix-xor in reverse order because
        in question we have asked xor of complete list in first query
        """