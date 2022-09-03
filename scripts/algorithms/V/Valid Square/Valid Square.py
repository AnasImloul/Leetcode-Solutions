# Runtime: 65 ms (Top 24.05%) | Memory: 13.9 MB (Top 50.57%)
class Solution:
    def validSquare(self, p1, p2, p3, p4):

        def cal(A, B):
            return abs(A[0] - B[0]) + abs(A[1] - B[1])

        d = [cal(p1, p2), cal(p1, p3), cal(p1, p4), cal(p2, p3), cal(p2, p4), cal(p3, p4)]
        d.sort()

        return 0 < d[0] == d[1] == d[2] == d[3] and d[4] == d[5]
