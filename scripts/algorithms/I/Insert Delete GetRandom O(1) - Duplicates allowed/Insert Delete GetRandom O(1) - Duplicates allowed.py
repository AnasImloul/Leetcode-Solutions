class RandomizedCollection:

    def __init__(self):
        self.items = []

    def insert(self, val: int) -> bool:
        self.items.append(val)
        if self.items.count(val) > 1:
            return False
        else:
            return True

    def remove(self, val: int) -> bool:
        if val in self.items:
            flag = True
            self.items.remove(val)
        else:
            flag = False
        
        return flag

    def getRandom(self) -> int:
        return choice(self.items)
            
