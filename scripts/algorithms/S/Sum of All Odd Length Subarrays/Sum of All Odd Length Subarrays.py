// Runtime: 33 ms (Top 98.51%) | Memory: 16.50 MB (Top 56.37%)

class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        
        length = len(arr)
        ans = 0
        
        for i in range(length) :
            ans += ((i+1)*(length-i)+1)//2 * arr[i]
        return ans;
