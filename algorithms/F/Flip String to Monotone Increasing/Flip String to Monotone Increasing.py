class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        n = len(s)
        min_flip = n
        one_left = 0
        # zero_right = 0
        # for c in s:
        #     if c == "0":
        #         zero_right += 1
        
        zero_right = s.count("0") # since we will start with 11...11 then every zero in s will be on the right side of the border
        
        # for each i imagine that we have the borderline at i index any index >= i will be 1 and index < i will be 0.
        # i = 0, n = 5 -> 11111
        # i = 1, n = 5 -> 01111
        # i = 5        -> 00000
        for i in range(n + 1):
            # the number of flip will be equal number of 1 on the left side of the border + number of zero on the right side of the border
            # from example     00110
            #                    v 
            # comparing with   00111  : i = 2, one_left = 0, zero_right = 1, then we have to do 0 + 1 flip in this i
            min_flip = min(min_flip,one_left+zero_right)
            
            # edge case for i = n or all zero (00...00)
            if i == len(s):
                continue
            # reduce count of zero_right when 0 is moving to the 0-zone or left side of border
            if s[i] == "0":
                zero_right -= 1
            else:
                one_left += 1 # increase one on the left side when we move 1 into the left side
        
        return min_flip
            
            
