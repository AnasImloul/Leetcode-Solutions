# Runtime: 3867 ms (Top 5.16%) | Memory: 20.8 MB (Top 90.23%)
class Skiplist:
    def __init__(self):
        self.data = []
    def search(self, target: int) -> bool:
        if target in self.data:
            return True
        else:
            return False
    def add(self, num: int) -> None:
        self.data.append(num)
    def erase(self, num: int) -> bool:
        for i in range(len(self.data)):
            if self.data[i] == num:
                self.data.pop(i)
                return True
        if num not in self.data:
            return False