class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        
         if n == 0: return False
        
         k = n
         while k != 1:
             if k % 2 != 0:
                 return False
             k = k // 2
            
            
         return True

        count = 0
        for i in range(33):
            mask = 1 << i
            
            if mask & n:
                count += 1
                
            if count > 1:
                return False
                
        if count == 1:
            return True
        return False
		
