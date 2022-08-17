class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
         def climb(n):
             if n==1: #only one step option is availble
                 return 1
             if n ==2: # two options are possible : to take two 1-stpes or to only take one 2-steps
                 return 2
             return climb(n-1) + climb(n-2)
         return climb(n)
