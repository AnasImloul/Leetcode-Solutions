class Solution:
    def HHMMToMinutes(self, s: str) -> int:
        return int(s[0:2])*60 + int(s[3:5])
    def convertTime(self, current: str, correct: str) -> int:
        diff = self.HHMMToMinutes(correct) - self.HHMMToMinutes(current)
        order = [60,15,5,1]
        ops = 0
        for i in range(0,4):
            ops+=int(diff/order[i])
            diff%=order[i]
        return ops
