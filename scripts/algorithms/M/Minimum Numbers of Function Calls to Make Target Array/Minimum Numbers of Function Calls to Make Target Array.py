# Observe that:
#   +1  places a 1 to the end of the int's binary representation
#       (assuming a 0 there previously)
#   x2  is a bitshift left
# So you basically just need to count all the ones in the binary representations
# and find how many shifts are required (largest bit length minus one).

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        if max(nums) == 0:
            return 0
        
        return sum([x.bit_count() for x in nums]) + max([x.bit_length() for x in nums]) - 1

