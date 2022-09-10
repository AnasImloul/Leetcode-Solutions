# Runtime: 514 ms (Top 80.64%) | Memory: 14.5 MB (Top 44.35%)
from graphlib import TopologicalSorter, CycleError

Color = int
Corner = Tuple[int, int]
Rect = Tuple[Corner, Corner] # [upper-left, lower-right (non-inclusive)]
Layer = Tuple[Color, Rect]

class Solution:
    def isPrintable(self, targetGrid: List[List[int]]) -> bool:
        # Runtime is the summation of several steps but is dominated by the second step
        # O(M*N + C*C*M*N + (O(C*C) + O(M*N)) + M*N) -> O(C*C*M*N)
        def compare(a:Layer, b:Layer) -> int:
            """
            Determine if two rectangles overlap.

            Return:
                -1 if b is over a
                0 if there is no overlap or an order cannot be determined (the overlap contains no elements of a or b)
                1 if a is over b
            """
            val_a, (a_ul, a_lr) = a
            val_b, (b_ul, b_lr) = b

            # Get overlap rectangle
            ul, lr = (
                (max(a_ul[0], b_ul[0]), max(a_ul[1], b_ul[1])),
                (min(a_lr[0], b_lr[0]), min(a_lr[1], b_lr[1])),
            )

            # If either dimension is non-positive, there is no overlap
            if lr[0] - ul[0] <= 0 or lr[1] - ul[1] <= 0:
                return 0

            # Find the first element matching a or b in the overlap rectangle.
            # We'll consider that the "over" value.
            for r in range(ul[0], lr[0]):
                for c in range(ul[1], lr[1]):
                    if targetGrid[r][c] == val_b:
                        return -1
                    elif targetGrid[r][c] == val_a:
                        return 1
            # We could find no values from a or b in the overlap.
            # The result is indeterminate.
            return 0

        # Generate the enclosing rectangles for each visible color (ie. layers).
        # O(M*N)
        rects:Dict[Color, Rect] = defaultdict(lambda: ([100, 100], [0, 0]))
        for r, row in enumerate(targetGrid):
            for c, val in enumerate(row):
                ul, lr = rects[val]
                rects[val] = (
                    (min(ul[0], r), min(ul[1], c)),
                    (max(lr[0], r + 1), max(lr[1], c + 1))
                )

        # Compare every pair of layers.
        # If overlap is detected, record that the "upper" rectangle depends on the "lower" one.
        # O(C*C*M*N) # Number of colors
        layers:List[Layer] = list(rects.items())
        graph:Dict[Layer, Set[Layer]] = {layer: set() for layer in layers}
        for i, a in enumerate(layers):
            for b in layers[i + 1 :]:
                if (cmp := compare(a, b)) < 0:
                    graph[b].add(a)
                elif cmp > 0:
                    graph[a].add(b)

        # Use topological sort on the graph to reproduce the printing order (in the absence
        # of cycles) and print our own grid.
        # O(C*C) + O(M*N) // O(C*C) is derived from topological sort O(V+E)
        try:
            grid = [[0] * len(targetGrid[0]) for _ in targetGrid]
            for color, (ul, lr) in TopologicalSorter(graph).static_order():
                for r in range(ul[0], lr[0]):
                    for c in range(ul[1], lr[1]):
                        grid[r][c] = color
        except CycleError:
            return False

        # Compare the grids
        # O(M*N)
        return grid == targetGrid