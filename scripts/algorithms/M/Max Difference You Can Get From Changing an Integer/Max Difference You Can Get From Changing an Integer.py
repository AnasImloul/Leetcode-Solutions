// Runtime: 34 ms (Top 82.14%) | Memory: 16.40 MB (Top 63.78%)

class Solution:
    def maxDiff(self, num: int) -> int:
        num = str(num)
        
        i = next((i for i in range(len(num)) if num[i] != "9"), -1) #first non-9 digit
        hi = int(num.replace(num[i], "9"))
        
        if num[0] != "1": lo = int(num.replace(num[0], "1"))
        else: 
            i = next((i for i in range(len(num)) if num[i] not in "01"), -1)
            lo = int(num.replace(num[i], "0") if i > 0 else num)
            
        return hi - lo
