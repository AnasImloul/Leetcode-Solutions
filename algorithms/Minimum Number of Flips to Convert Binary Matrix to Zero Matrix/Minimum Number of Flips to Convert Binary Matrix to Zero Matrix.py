class Solution:
    flips = [11, 23, 38, 89, 186, 308, 200, 464, 416]
    
    def minFlips(self, mat: List[List[int]]) -> int:
        mask = self.make_mask(mat)
        check = self.make_mask([[1 for c in r] for r in mat])
        min_steps = -1
        last = 0
        for x in range(2**9):
            x = x & check
            flips = last ^ x
            last = x
            if not flips:
                continue
            for i in range(len(mat)):
                for j in range(len(mat[0])):
                    index = (i * 3 + j)
                    if 1 << index & flips:
                        mask ^= self.flips[index]
            if check & ~mask == check:
                steps = self.count_bits(x & check)
                if min_steps < 0 or steps < min_steps:
                    min_steps = steps
        return min_steps
    
    def make_mask(self, mat):
        d = 0
        for i in range(3):
            for j in range(3):
                if i < len(mat) and j < len(mat[0]):
                    d |= mat[i][j] << (i * 3 + j)
        return d

    def count_bits(self, x):
        count = 0
        i = 1
        while i <= x:
            count += int(bool(x & i))
            i <<= 1
        return count
