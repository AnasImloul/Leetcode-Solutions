# Runtime: 600 ms (Top 65.10%) | Memory: 33.5 MB (Top 72.09%)
class SnapshotArray:

    def __init__(self, length: int):
        self.snap_id = 0
        self.history = defaultdict(dict)

    def set(self, index: int, val: int) -> None:
        self.history[self.snap_id][index] = val

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id-1

    def get(self, index: int, snap_id: int) -> int:
        for i in range(snap_id,-1,-1):
            if index in self.history[i]:
                return self.history[i][index]
        return 0 # default value in case it wasn't set earlier