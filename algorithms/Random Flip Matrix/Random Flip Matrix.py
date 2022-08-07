from random import randint

class Solution:

    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.ones = set()

    def flip(self) -> List[int]:
        i, j = randint(0, self.m - 1), randint(0, self.n - 1)
        while (i, j) in self.ones:
            i, j = randint(0, self.m - 1), randint(0, self.n - 1)
        self.ones.add((i, j))
        return [i, j]

    def reset(self) -> None:
        self.ones.clear()
