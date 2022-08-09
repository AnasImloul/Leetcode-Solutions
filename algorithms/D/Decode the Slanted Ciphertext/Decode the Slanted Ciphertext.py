class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        cols, res = len(encodedText) // rows, ""
        for i in range(cols):
            for j in range(i, len(encodedText), cols + 1):
                res += encodedText[j]
        return res.rstrip()
