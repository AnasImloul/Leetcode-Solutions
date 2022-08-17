class RandomizedSet:

    def __init__(self):
        self.data = set() 

    def insert(self, val: int) -> bool:
      if val not in self.data:
        self.data.add(val)
        return True 
      return False 
        
    def remove(self, val: int) -> bool:
        if val in self.data:
          self.data.remove(val)
          return True 
        return False 

    def getRandom(self) -> int:
        return  random.choice(list(self.data))
