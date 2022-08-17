class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        return max(
            (
                (sum(qi // (1 + dist) for xi, yi, qi in towers if (dist := sqrt((xi - x) ** 2 + (yi - y) ** 2)) <= radius),
                 [x, y]) for x in range(51) for y in range(51)
            ),
            key=lambda x: (x[0], -x[1][0], -x[1][1])
        )[1]
