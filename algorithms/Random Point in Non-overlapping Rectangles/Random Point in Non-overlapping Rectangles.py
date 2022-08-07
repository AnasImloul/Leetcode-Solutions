class Solution:
    """
    1 <= rects.length <= 100
    rects[i].length == 4
    -10^9 <= ai < xi <= 10^9
    -10^9 <= bi < yi <= 10^9
    xi - ai <= 2000
    yi - bi <= 2000
    All the rectangles do not overlap.
    At most 10^4 calls will be made to pick.
    """

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.n_range = list(range(len(self.rects)))
        self.weights = [(x[2] - x[0] + 1) * (x[3] - x[1] + 1) for x in rects]

    def pick(self) -> List[int]:
        rect = self.rects[choices(self.n_range, self.weights, k=1)[0]]
        return [randint(rect[0], rect[2]), randint(rect[1], rect[3])]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
