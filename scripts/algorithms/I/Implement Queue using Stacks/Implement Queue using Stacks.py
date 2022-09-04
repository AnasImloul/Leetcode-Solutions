# Runtime: 53 ms (Top 33.00%) | Memory: 13.9 MB (Top 98.49%)
class MyStack:
    def __init__(self):
        self.stack = []

    def push(self, x):
        self.stack.append(x)

    def top(self):
        return self.stack[-1]

    def pop(self):
        return self.stack.pop()

    def size(self):
        return len(self.stack)

    def isEmpty(self):
        return len(self.stack) == 0

class MyQueue:

    def __init__(self):
        self.stack1 = MyStack()
        self.stack2 = MyStack()

    def push(self, x: int) -> None:
        self.stack1.push(x)

    def pop(self) -> int:
        while not self.stack1.isEmpty():
            self.stack2.push(self.stack1.pop())
        out = self.stack2.pop()
        while not self.stack2.isEmpty():
            self.stack1.push(self.stack2.pop())
        return out

    def peek(self) -> int:
        while not self.stack1.isEmpty():
            self.stack2.push(self.stack1.pop())
        out = self.stack2.top()
        while not self.stack2.isEmpty():
            self.stack1.push(self.stack2.pop())
        return out

    def empty(self) -> bool:
        return self.stack1.isEmpty()

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()