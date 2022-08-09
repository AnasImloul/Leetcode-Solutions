class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class BrowserHistory:
    def __init__(self, web):
        self.Node = Node(web)
        self.ptr = self.Node

    def visit(self, web):
        self.newWeb = Node(web)
        self.newWeb.prev = self.ptr
        self.ptr.next = self.newWeb
        self.ptr = self.ptr.next
        
    def back(self, steps):
        i = 0
        while i  < steps:
            if self.ptr.prev:
                self.ptr = self.ptr.prev
            else:
                break
            i += 1
        return self.ptr.val

    def forward(self, steps):
        i = 0
        while i < steps:
            if self.ptr.next:
                self.ptr = self.ptr.next
            else:
                break
            i += 1
        return self.ptr.val
