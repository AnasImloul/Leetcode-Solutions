// Runtime: 53 ms (Top 90.74%) | Memory: 14.1 MB (Top 53.70%)
class Solution:
    def getProbability(self, balls: List[int]) -> float:
        m = len(balls)
        N = sum(balls)
        n = N // 2

        prefix = [0] * m
        for i in range(m):
            prefix[i] = prefix[i-1] + balls[i]

        # STEP 1: Compute the number of ways to pick j balls from i total, i.e. C(i, j)
        choose = [[0] * (N + 1) for i in range(N + 1)]
        choose[0][0] = 1
        for i in range(1, N + 1):
            for pick in range(N + 1):
                # DECISION 1: don't pick the ith ball
                choose[i][pick] += choose[i - 1][pick]
                # DECISION 2: pick the ith ball
                choose[i][pick] += choose[i - 1][pick - 1]

        # STEP 2: From first i ball types, compute ways to:
        # - pick c1 balls in box1
        # - such that the difference in unique ball count between box1 and box2 is d
        ways = [[defaultdict(int) for k in range(n + 1)] for i in range(m + 1)]
        ways[0][0][0] = 1

        for i in range(m):
            b = balls[i]
            if i == 0:
                prev_total = 0
            else:
                prev_total = prefix[i - 1]
            for c1 in range(n + 1):
                c2 = prev_total - c1
                if c2 < 0:
                    continue
                for d in ways[i][c1]:
                    for add1 in range(b + 1):
                        add2 = b - add1
                        if c1 + add1 > n:
                            continue
                        if c2 + add2 > n:
                            continue
                        if add1 == b:
                            delta = 1
                        elif add2 == b:
                            delta = -1
                        else:
                            delta = 0
                        ways_to_add = choose[b][add1] * ways[i][c1][d]
                        ways[i + 1][c1 + add1][d + delta] += ways_to_add

        # compute the actual probability
        return ways[m][n][0] / choose[N][n]