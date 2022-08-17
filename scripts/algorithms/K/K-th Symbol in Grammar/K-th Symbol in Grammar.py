class Solution:
  def solve(self,n,k):
    if n==1 and k==1:
      return 0 
    mid = pow(2,n-1)//2 
    if k<=mid:
      return self.solve(n-1,k) 
    
    return not self.solve(n-1,k-mid)
    
      
  def kthGrammar(self,n,k):
    if self.solve(n,k):
      return 1 
    else:
      return 0 
      
    
   
    
    
    
    
    
    
    
