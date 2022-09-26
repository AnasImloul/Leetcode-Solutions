# Runtime: 328 ms (Top 5.22%) | Memory: 13.9 MB (Top 17.87%)
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        charValue = [0] * 26
        for i in range(len(order)):
            idx = ord(order[i]) - ord('a')
            charValue[idx] = 26 - i

        arrS = []
        n = 0
        for c in s:
            arrS.append(c)
            n += 1

        sorted = False
        while not sorted:
            sorted = True
            for i in range(n - 1):
                if charValue[ord(arrS[i]) - ord('a')] < charValue[ord(arrS[i + 1]) - ord('a')]:
                    sorted = False
                    arrS[i], arrS[i + 1] = arrS[i + 1], arrS[i]

        return ''.join(arrS)