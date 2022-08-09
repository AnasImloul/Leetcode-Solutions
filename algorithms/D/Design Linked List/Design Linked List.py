class Node:
    def __init__(self, val: int):
        self.val = val
        self.next = None
        self.prev = None
        
class MyLinkedList:
    def __init__(self):
        self.head = Node(0)
        self.tail = Node(0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.size = 0
        
    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        # Distance of index is closer to head
        if index + 1 < self.size - index:
            curr = self.head
            for i in range(index + 1):
                curr = curr.next
        # Distance of index is closer to tail
        else:
            curr = self.tail
            for i in range(self.size - index):
                curr = curr.prev
        return curr.val

    def addAtHead(self, val: int) -> None:
        curr = Node(val)
        prevNode = self.head
        nextNode = self.head.next
        self.size += 1
        curr.prev = prevNode
        curr.next = nextNode
        prevNode.next = curr
        nextNode.prev = curr

    def addAtTail(self, val: int) -> None:
        curr = Node(val)
        prevNode = self.tail.prev
        nextNode = self.tail
        self.size += 1
        curr.prev = prevNode
        curr.next = nextNode
        prevNode.next = curr
        nextNode.prev = curr

    def addAtIndex(self, index: int, val: int) -> None:
        curr = Node(val)
        if index > self.size:
            return
        if index < 0:
            index = 0
        if index < self.size - index:
            prevNode = self.head
            for i in range(index):
                prevNode = prevNode.next
            nextNode = prevNode.next
        else:
            nextNode = self.tail
            for i in range(self.size - index):
                nextNode = nextNode.prev
            prevNode = nextNode.prev
        self.size += 1
        curr.prev = prevNode
        curr.next = nextNode
        prevNode.next = curr
        nextNode.prev = curr
        
    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return 
        if index < self.size - index:
            prevNode = self.head
            for i in range(index):
                prevNode = prevNode.next
            nextNode = prevNode.next.next
        else:
            nextNode = self.tail
            for i in range(self.size - index - 1):
                nextNode = nextNode.prev
            prevNode = nextNode.prev.prev
        self.size -= 1
        prevNode.next = nextNode
        nextNode.prev = prevNode


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)