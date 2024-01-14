// Runtime: 57 ms (Top 91.39%) | Memory: 18.00 MB (Top 39.07%)

class MyCircularDeque:
  def __init__(self, k: int):
    self.queue = [None] * k
    self.max_size = k
    self.head = 0
    self.tail = 0
    self.size = 0

  def insertFront(self, value: int) -> bool:
    if self.isFull():
        return False
    self.head = (self.head - 1) % self.max_size
    self.queue[self.head] = value
    self.size += 1
    return True

  def insertLast(self, value: int) -> bool:
    if self.isFull():
        return False
    self.queue[self.tail] = value
    self.tail = (self.tail + 1) % self.max_size
    self.size += 1
    return True

  def deleteFront(self) -> bool:
    if self.isEmpty():
        return False
    self.head = (self.head + 1) % self.max_size
    self.size -= 1
    return True

  def deleteLast(self) -> bool:
    if self.isEmpty():
        return False
    self.tail = (self.tail - 1) % self.max_size
    self.size -= 1
    return True

  def getFront(self) -> int:
    if self.isEmpty():
        return -1
    return self.queue[self.head]

  def getRear(self) -> int:
    if self.isEmpty():
        return -1
    return self.queue[(self.tail - 1) % self.max_size]

  def isEmpty(self) -> bool:
    return self.size == 0

  def isFull(self) -> bool:
    return self.size == self.max_size

