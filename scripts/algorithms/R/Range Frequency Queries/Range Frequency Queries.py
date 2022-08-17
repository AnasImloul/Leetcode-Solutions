class RangeFreqQuery:
    def __init__(self, arr: List[int]):
        self.l = [[] for _ in range(10001)]
        for i, v in enumerate(arr):
            self.l[v].append(i)
    def query(self, left: int, right: int, v: int) -> int:
        return bisect_right(self.l[v], right) - bisect_left(self.l[v], left)
