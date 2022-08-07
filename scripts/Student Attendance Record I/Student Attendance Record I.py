class Solution:
    def checkRecord(self, s: str) -> bool:
        eligible = True
        
        for i in range(0, len(s)-2):
            if s[i:i+3] == "LLL":
                eligible = False
        absent = 0
        for i in range(len(s)):
            if s[i] == "A":
                absent +=1 
                
        if absent>=2:
            eligible = False
            
        return(eligible)
