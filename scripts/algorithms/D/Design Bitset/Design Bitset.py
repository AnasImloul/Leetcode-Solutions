# Runtime: 1967 ms (Top 8.78%) | Memory: 45.4 MB (Top 61.95%)
class Bitset(object):

    def __init__(self, size):
        self.a = 0
        self.size = size
        self.cnt = 0

    def fix(self, idx):
        if self.a & (1 << idx) == 0:
            self.a |= 1 << idx
            self.cnt += 1

    def unfix(self, idx):
        if self.a & (1 << idx):
            self.a ^= 1 << idx
            self.cnt -= 1

    def flip(self):
        self.a ^= (1 << self.size) - 1
        self.cnt = self.size - self.cnt

    def all(self):
        return self.cnt == self.size

    def one(self):
        return self.a > 0

    def count(self):
        return self.cnt

    def toString(self):
        a = bin(self.a)[2:]
        return a[::-1] + '0' * (self.size - len(a))