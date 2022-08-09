class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        ogLength = intLength
        isOdd = intLength & 1
        if isOdd:
            intLength += 1
        k = intLength // 2
        k = 10 ** (k - 1)
        op = []
        for q in queries:
            pal = str(k + q - 1)
            if isOdd:
                pal += pal[::-1][1:]
            else:
                pal += pal[::-1]
            if len(pal) == ogLength:
                op.append(int(pal))
            else:
                op.append(-1)
        return op
