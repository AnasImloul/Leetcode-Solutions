class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        
        def find(a1, a2, aCenter):
            if a1 <= aCenter and aCenter <= a2:
                return 0 
            elif a1 > aCenter:
                return  a1 - aCenter
            else:
                return aCenter - a2

        return (find(x1, x2, xCenter))**2 + (find(y1, y2, yCenter))**2 <= radius**2 
	```