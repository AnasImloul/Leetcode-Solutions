class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        n = len(encodedText)
        cols = n // rows
        step = cols + 1
        res = ""
        
        for i in range(cols):
            for j in range(i, n, step):
                res += encodedText[j]
            
        return res.rstrip()