# Runtime: 347 ms (Top 94.76%) | Memory: 22.7 MB (Top 60.86%)
class FreqStack:

    def __init__(self):
        self.cnt = {}
        self.maxcount = 0
        self.stack = {}

    def push(self, val: int) -> None:
        count = self.cnt.get(val,0)+1
        self.cnt[val] = count
        if count>self.maxcount:
            self.maxcount = count
            self.stack[count] = []
        self.stack[count].append(val)

    def pop(self) -> int:
        res = self.stack[self.maxcount].pop()
        self.cnt[res]-=1
        if not self.stack[self.maxcount]:
            self.maxcount-=1
        return res

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()