// Runtime: 405 ms (Top 95.45%) | Memory: 42.30 MB (Top 90.53%)

class DataStream:

    def __init__(self, value: int, k: int):
        self.v = value
        self.k = k
        self.n = 0

    def consec(self, num: int) -> bool:
        if num == self.v:
            self.n += 1
        else:
            self.n = 0

        return self.n >= self.k
