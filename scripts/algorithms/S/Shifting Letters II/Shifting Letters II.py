class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        totalShifts = [0] * (n + 1)
        for start, end, direction in shifts:
            if not direction:
                direction = -1
            totalShifts[start] += direction
            totalShifts[end + 1] -= direction
        
        for i in range(1, n):
            totalShifts[i] += totalShifts[i - 1]
        
        res = []
        for c, totalShift in zip(s, totalShifts):
            res.append(chr((ord(c) - 97 + totalShift) % 26 + 97))
        return ''.join(res)