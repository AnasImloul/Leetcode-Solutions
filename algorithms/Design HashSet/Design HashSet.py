class MyHashSet:

    def __init__(self):
        self.hash_list = [0]*10000000
        

    def add(self, key: int) -> None:
        self.hash_list[key]+=1
        

    def remove(self, key: int) -> None:
        self.hash_list[key] = 0
        

    def contains(self, key: int) -> bool:
        if self.hash_list[key] > 0:
            return True
        return False
