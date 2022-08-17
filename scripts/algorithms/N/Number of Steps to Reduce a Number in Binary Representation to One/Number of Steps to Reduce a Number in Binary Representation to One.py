
class Solution:
    def numSteps(self, s: str) -> int:
        size = len(s)
        if size == 1:
            return 0
        one_group = s.split('0')
        zero_group = s.split('1')

        
        if size - len(zero_group[-1]) == 1:
            return size - 1
        else:
            return size + len(one_group) - len(zero_group[-1])
