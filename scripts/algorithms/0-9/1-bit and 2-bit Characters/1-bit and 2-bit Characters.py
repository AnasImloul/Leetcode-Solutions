# Dev: Chumicat
# Date: 2019/11/30
# Submission: https://leetcode.com/submissions/detail/282638543/
# (Time, Space) Complexity : O(n), O(1)

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        """
        :type bits: List[int]
        :rtype: bool
        """
        # Important Rules:
        # 1. If bit n is 0, bit n+1 must be a new char
        # 2. If bits end with 1, last bit must be a two bit char
        #    However, this case had been rejected by question
        # 3. If 1s in row and end with 0, 
        #    we can use count or 1s to check last char
        #    If count is even, last char is "0"
        #    If count is odd,  last char is "10"
        # Strategy:
        # 1. We don't care last element, since it must be 0.
        # 2. We check from reversed, and count 1s in a row
        # 3. Once 0 occur or list end, We stop counting
        # 4. We use count to determin result
        # 5. Since we will mod count by 2, we simplify it to bool
        ret = True
        for bit in bits[-2::-1]:
            if bit: ret = not ret
            else: break
        return ret
