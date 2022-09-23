# Runtime: 2359 ms (Top 39.76%) | Memory: 44.3 MB (Top 93.27%)
from math import ceil, log2
from typing import List

NO_PARENT = -1

class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.parent = [[NO_PARENT] * n for _ in range(ceil(log2(n + 1)))]
        self.__initialize(parent)

    def __initialize(self, parent: List[int]):
        self.parent[0], prev = parent, parent

        for jump_pow in range(1, len(self.parent)):
            cur = self.parent[jump_pow]

            for i, p in enumerate(prev):
                if p != NO_PARENT:
                    cur[i] = prev[p]

            prev = cur

    def getKthAncestor(self, node: int, k: int) -> int:
        jump_pow = self.jump_pow

        while k > 0 and node != NO_PARENT:
            jumps = 1 << jump_pow

            if k >= jumps:
                node = self.parent[jump_pow][node]
                k -= jumps
            else:
                jump_pow -= 1

        return node

    @property
    def jump_pow(self) -> int:
        return len(self.parent) - 1