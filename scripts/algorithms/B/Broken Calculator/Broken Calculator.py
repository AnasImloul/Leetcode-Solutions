class Solution(object):
    def brokenCalc(self, startValue, target):
        """
        :type startValue: int
        :type target: int
        :rtype: int
        """
        res = 0
        while target > startValue:
            res += 1
            if target % 2:
                target += 1
            else:
                target //= 2
        return res + startValue - target
