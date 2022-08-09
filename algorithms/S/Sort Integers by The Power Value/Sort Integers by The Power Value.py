class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
      self.store = {1:0}
      items = []
      for x in range(lo, hi+1):
        self.compute(x)
        items.append((self.store[x], x))
      items.sort()
      return items[k-1][1]
    
    def compute(self, x):
      if x in self.store:
        return self.store[x]
      y = x // 2 if x % 2 == 0 else 3 * x + 1
      self.store[x] = 1 + self.compute(y)
      return self.store[x]
