class Solution(object):
    def optimalDivision(self, nums):

        A = list(map(str, nums))
        
        
        if len(A) <= 2:
            
            return '/'.join(A)
        
        
        return A[0] + '/(' + '/'.join(A[1:]) + ')'
