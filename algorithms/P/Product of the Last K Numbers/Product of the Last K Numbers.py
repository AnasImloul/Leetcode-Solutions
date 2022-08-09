class ProductOfNumbers:
    def __init__(self):
        self.prods = [1]
        self.max = 0

    def add(self, num: int) -> None:
        if num == 0:
            num = 1
            self.max = len(self.prods)
        self.prods.append(self.prods[-1] * num)

    def getProduct(self, k: int) -> int:
        if k >= len(self.prods) - self.max:
            return 0
        return self.prods[-1] // self.prods[-k-1]
