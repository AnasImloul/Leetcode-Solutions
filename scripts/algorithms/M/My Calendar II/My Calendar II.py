// Runtime: 175 ms (Top 97.99%) | Memory: 17.50 MB (Top 58.54%)

class Node:
    def __init__(self, start, end, val):
        self.start = start
        self.end = end
        self.val = val
        self.left = None
        self.right = None
    
    def insertable(self, node):
        if node.end <= node.start:
            return True
        if node.end <= self.start:
            if not self.left:
                return True
            else:
                return self.left.insertable(node)
        elif node.start >= self.end:
            if not self.right:
                return True
            else:
                return self.right.insertable(node)
        else:
            if self.val == 1:
                leftS = min(self.start, node.start)
                leftE = max(self.start, node.start)
                rightS = min(self.end, node.end)
                rightE = max(self.end, node.end)
                if not self.left and not self.right:
                    return True
                elif not self.left:
                    return self.right.insertable(Node(rightS, rightE, 1))
                elif not self.right:
                    return self.left.insertable(Node(leftS, leftE, 1))
                else:
                    resL = self.left.insertable(Node(leftS, leftE, 1))
                    resR = self.right.insertable(Node(rightS, rightE, 1))
                    if resL and resR:
                        return True
                    return False
            else:
                return False

    def insert(self, node):
        if node.end <= node.start:
            return
        
        if node.end <= self.start:
            if not self.left:
                self.left = node
            else:
                self.left.insert(node)
        elif node.start >= self.end:
            if not self.right:
                self.right = node
            else:
                self.right.insert(node)
        else:
            leftS = min(self.start, node.start)
            leftE = max(self.start, node.start)
            rightS = min(self.end, node.end)
            rightE = max(self.end, node.end)
            self.val += 1
            self.start, self.end = leftE, rightS  
            if not self.left and not self.right:  
                self.left = Node(leftS, leftE, 1) if leftS < leftE else None
                self.right = Node(rightS, rightE, 1) if rightS < rightE else None
            elif not self.left:
                self.left = Node(leftS, leftE, 1) if leftS < leftE else None
                self.right.insert(Node(rightS, rightE, 1))
            elif not self.right:
                self.right = Node(rightS, rightE, 1) if rightS < rightE else None
                self.left.insert(Node(leftS, leftE, 1))
            else:
                self.left.insert(Node(leftS, leftE, 1))
                self.right.insert(Node(rightS, rightE, 1))
        return


class MyCalendarTwo:

    def __init__(self):
        self.root = None

    def book(self, start: int, end: int) -> bool:
        if not self.root:
            self.root = Node(start, end, 1)
            return True
        else:
            newNode = Node(start, end, 1)
            if self.root.insertable(newNode):
                self.root.insert(newNode)
                return True
            return False
