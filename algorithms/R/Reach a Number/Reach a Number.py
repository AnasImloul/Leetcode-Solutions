class Solution: 
  def  reachNumber(self,target):
    jumpCount = 1 
    sum = 0 
    while sum<abs(target):
      sum+=jump 
      jumpCount+=1 
    
    if (sum-target)%2==0: return jumpCount-1 
    else:
      
      if ((sum+jumpCount)-target)%2==0: 
        return jumpCount
      else:
        return jumpCount+1 
