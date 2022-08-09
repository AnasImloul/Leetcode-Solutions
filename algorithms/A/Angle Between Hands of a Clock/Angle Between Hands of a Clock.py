class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        
        x = abs(minutes * 6 -(hour * 30 + minutes/2))
        return min(360-x , x)
