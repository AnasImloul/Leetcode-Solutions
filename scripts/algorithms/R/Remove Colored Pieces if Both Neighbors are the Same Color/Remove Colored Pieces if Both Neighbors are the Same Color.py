class Solution:
    def winnerOfGame(self, s: str) -> bool:
        
        a = b = 0
        
        for i in range(1,len(s)-1):
            if s[i-1] == s[i] == s[i+1]:
                if s[i] == 'A':
                    a += 1
                else:
                    b += 1
                    
        return a>b
