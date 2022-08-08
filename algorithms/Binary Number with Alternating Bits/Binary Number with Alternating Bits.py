class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bin_n = bin(n)[2:]
        for i in range(len(bin_n)-1):
            if bin_n[i] == '0' and bin_n[i+1] == '0':
                return False
            
            if bin_n[i] == '1' and bin_n[i+1] == '1':
                return False
            
        return True

