// Runtime: 1014 ms (Top 83.89%) | Memory: 42.00 MB (Top 62.92%)

class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        n = len(s)
        d = [0 for _ in range(n + 1)]
        for start, end, direction in shifts:
            dir = 1 if direction else -1
            d[start] += dir
            d[end + 1] -= dir
        
        res = []
        for i in range(n):
            if i != 0: 
                d[i] += d[i - 1]
            new_chr_ascii = (ord(s[i]) - ord("a") + d[i]) % 26 + ord("a")
            res.append(chr(new_chr_ascii))
        return "".join(res)
