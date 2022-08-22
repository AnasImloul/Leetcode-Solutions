# Runtime: 1147 ms (Top 25.09%) | Memory: 14.8 MB (Top 29.59%)
class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])

        def avg(i, j):
            s = squares = 0
            top, bottom = max(0, i - 1), min(m, i + 2)
            left, right = max(0, j - 1), min(n, j + 2)

            for x in range(top, bottom):
                for y in range(left, right):
                    s += img[x][y]
                    squares += 1

            return s // squares

        return [[avg(i, j) for j in range(n)] for i in range(m)]