# Runtime: 2037 ms (Top 14.35%) | Memory: 17.2 MB (Top 80.82%)
class MyHashMap:

    def __init__(self):
        self.keys = []
        self.values = []

    def put(self, key: int, value: int) -> None:
        if key not in self.keys:
            self.keys.append(key)
            self.values.append(value)
        else:
            idx = self.keys.index(key)
            self.values[idx] = value

    def get(self, key: int) -> int:
        if key not in self.keys:
            return -1
        idx = self.keys.index(key)
        return self.values[idx]

    def remove(self, key: int) -> None:
        if key in self.keys:
            idx = self.keys.index(key)
            del self.keys[idx]
            del self.values[idx]