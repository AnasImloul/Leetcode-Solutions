class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = [start + 2*i for i in range(n)] #generate list of numbers
        ans = nums[0]
        for i in range(1,n):
            ans = ans^nums[i] # XOR operation
        return ans
        
        
