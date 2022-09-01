# Runtime: 176 ms (Top 11.57%) | Memory: 14.6 MB (Top 46.27%)
class FrontMiddleBackQueue:

    def __init__(self):
        self.front = deque()
        self.back = deque()

    def _correct_size(self):
        while len(self.back) > len(self.front):
            self.front.append(self.back.popleft())

        while len(self.front) > len(self.back) + 1:
            self.back.appendleft(self.front.pop())

    def pushFront(self, val: int) -> None:
        self.front.appendleft(val)
        self._correct_size()

    def pushMiddle(self, val: int) -> None:
        if len(self.front) > len(self.back):
            self.back.appendleft(self.front.pop())
        self.front.append(val)
        self._correct_size()

    def pushBack(self, val: int) -> None:
        self.back.append(val)
        self._correct_size()

    def popFront(self) -> int:
        front = self.front if self.front else self.back
        ret = front.popleft() if front else -1
        self._correct_size()
        return ret

    def popMiddle(self) -> int:
        ret = self.front.pop() if self.front else -1
        self._correct_size()
        return ret

    def popBack(self) -> int:
        back = self.back if self.back else self.front
        ret = back.pop() if back else -1
        self._correct_size()
        return ret