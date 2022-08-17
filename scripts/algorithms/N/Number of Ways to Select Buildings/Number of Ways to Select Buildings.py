class Solution:
    def numberOfWays(self, s: str) -> int:
        
        temp = []
        c0 = 0
        c1 = 0
        for char in s :
            if char == "0" :
                c0+=1
            else:
                c1+=1
            temp.append([c0,c1])
            
        total0 = c0
        total1 = c1
        
        
        count = 0
        for i in range(1, len(s)-1) :
            
            if s[i] == "0" :
                m1 = temp[i-1][1]
                m2 = total1 - temp[i][1]
                count += m1*m2
                
            else:
                m1 = temp[i-1][0]
                m2 = total0 - temp[i][0]
                count += m1*m2
        return count
                
        
