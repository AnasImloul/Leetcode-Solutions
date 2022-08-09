class Solution:
    @cache
    def twoEggDrop(self, n: int) -> int:
        return min((1 + max(i - 1, self.twoEggDrop(n - i)) for i in range (1, n)), default = 1)
