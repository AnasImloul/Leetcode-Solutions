# Runtime: 89 ms (Top 30.66%) | Memory: 13.8 MB (Top 76.49%)
class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        sum = 0;
        for i in range(0, len(s) - 1):
            curr = roman[s[i]]
            nxt = roman[s[i + 1]]
            if curr < nxt:
                sum -= curr
            else:
                sum += curr
        sum += roman[s[-1]]
        return sum