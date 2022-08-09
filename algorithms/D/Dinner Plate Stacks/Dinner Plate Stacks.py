class DinnerPlates:

    def __init__(self, capacity: int):
        self.heap = []
        self.stacks = []
        self.capacity = capacity

    def push(self, val: int) -> None:
        if self.heap:
            index = heapq.heappop(self.heap)
            if index < len(self.stacks):
                self.stacks[index].append(val)
            else:
                self.push(val)
        elif self.stacks:
            lastStack = self.stacks[-1]
            if len(lastStack) != self.capacity:
                lastStack.append(val)
            else:
                stack = deque()
                stack.append(val)
                self.stacks.append(stack)
        else:
            stack = deque()
            stack.append(val)
            self.stacks.append(stack)
            
    def pop(self) -> int:
        while self.stacks:
            lastStack = self.stacks[-1]
            if lastStack:
                val = lastStack.pop()
                if not lastStack:
                    self.stacks.pop()
                return val
            else:
                self.stacks.pop()
        return -1

    def popAtStack(self, index: int) -> int:
        if index == len(self.stacks) - 1:
            return self.pop()
        if index < len(self.stacks):
            stack = self.stacks[index]
            if stack:
                val = stack.pop()
                heapq.heappush(self.heap, index)
                return val
        return -1


# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
