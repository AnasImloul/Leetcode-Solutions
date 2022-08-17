class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        # since integer has no length function, we convert our num into a str.
        # Then we run a loop that goes until i+k-1 < len(numStr) and take
        # n = int(numStr[i: i+k]); and if n!=0 and num%n==0 meaning 
		# num is divisible by n so we add 1 to k_beauty and return it in the end.
		
        numStr = str(num)
        i, k_beauty = 0, 0
        
        while i+k-1 < len(numStr):
            n = int(numStr[i: i+k])
            if n!=0 and num%n==0:
                k_beauty += 1
                
            i += 1
        
        return k_beauty
