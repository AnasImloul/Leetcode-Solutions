class Solution:
  def possible (self,distance,positions,M):
    ball = 1 
    lastPos = positions[0]  
    for pos in positions:
      if pos-lastPos >= distance:
        ball+=1 
        if ball == M: return True 
        lastPos=pos 
     
    return False 
        
      
    
  def maxDistance(self, positions,M):
    positions.sort()
    low = 0 
    high = positions [-1] 
    ans = 0
    while low<=high:
      distance = low+(high-low)//2 
      
      if self.possible(distance,positions,M):
        ans = distance
        low=distance+1 
      else:
        high=distance-1 
    return ans 
