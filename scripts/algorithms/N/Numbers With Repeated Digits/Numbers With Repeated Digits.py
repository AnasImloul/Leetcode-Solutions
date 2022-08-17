class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        
        nums = [int(i) for i in str(n+1)] # digits in n+1
        d = len(nums) # number of digits in n+1
        res = 0 # number of no duplicates
        
        # count no duplicates for numbers with <d digits
        for i in range(1,d):
            res += 9 * math.perm(9,i-1)
        
		# count no duplicates for numbers with d digits and smaller than n
        for i, x in enumerate(nums):
            if i == 0:
                digit_range = range(1,x) # first digit can not be 0
            else:
                digit_range = range(x)
                
            for y in digit_range:
                if y not in nums[:i]:
                    res += math.perm(9-i,d-1-i)
            if x in nums[:i]: break
                
        return n - res
