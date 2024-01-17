// Runtime: 34 ms (Top 83.44%) | Memory: 17.40 MB (Top 22.74%)

class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        def get_time(t):
            hh, mm = t.split(':')
            return int(hh) * 60 + int(mm)
        
        current, correct = get_time(current), get_time(correct)
        operations = 0
        diff = correct - current
        
        for mins in [60, 15, 5, 1]:
            quotient, remainder = divmod(diff, mins)
            operations += quotient
            diff = remainder
                
        return operations
