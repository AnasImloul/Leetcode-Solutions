class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        
        Z = set()

        for i in range(len(s)-k+1):
            Z.add(s[i:i+k])
            
        if len(Z) == 2**k:
            return True

        return False