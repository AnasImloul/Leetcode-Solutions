// Runtime: 675 ms (Top 95.65%) | Memory: 40.70 MB (Top 63.04%)

from sortedcontainers import SortedList
class SORTracker:

    def __init__(self):
        self.arr=SortedList()
        self.index=-1
    def add(self, name: str, score: int) -> None:
        self.arr.add([-score,name])
        
    def get(self) -> str:
       
        self.index+=1
        return self.arr[self.index][1]


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name,score)
# param_2 = obj.get()
