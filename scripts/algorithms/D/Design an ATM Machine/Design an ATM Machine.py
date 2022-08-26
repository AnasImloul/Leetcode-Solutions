// Runtime: 906 ms (Top 67.28%) | Memory: 18 MB (Top 21.66%)
class ATM:
    def __init__(self):
        self.cash = [0] * 5
        self.values = [20, 50, 100, 200, 500]

    def deposit(self, banknotes_count: List[int]) -> None:
        for i, n in enumerate(banknotes_count):
            self.cash[i] += n

    def withdraw(self, amount: int) -> List[int]:
        res = []
        for val, n in zip(self.values[::-1], self.cash[::-1]):
            need = min(n, amount // val)
            res = [need] + res
            amount -= (need * val)
        if amount == 0:
            self.deposit([-x for x in res])
            return res
        else:
            return [-1]
