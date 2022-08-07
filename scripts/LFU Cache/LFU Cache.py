class Node:
    
    def __init__(self, key, val, cnt=1, nxxt=None, prev=None):
        self.key = key
        self.val = val
        self.cnt = cnt
        self.nxxt = nxxt
        self.prev = prev
        
        
class NodeList(Node):
    
    def __init__(self):
        self.head = Node(0,0)
        self.tail = Node(0,0)
        self.head.nxxt = self.tail
        self.tail.prev = self.head
        self.size = 0
        
        
    def addFront(self, node):
        temp = self.head.nxxt
        self.head.nxxt = node
        node.prev = self.head
        node.nxxt = temp
        temp.prev = node
        
        self.size += 1
        
        
    def removeNode(self, node):
        delprev = node.prev
        delnxxt = node.nxxt
        delprev.nxxt = delnxxt
        delnxxt.prev = delprev
        
        self.size -= 1
        

class LFUCache(NodeList):

    def __init__(self, capacity: int):
        self.keyNode = {}
        self.freqNodeList = {}
        self.maxSizeCache = capacity
        self.currSize = 0
        self.minFreq = 0
        
        
    def updateFreqNodeList(self, node):
        del self.keyNode[node.key]
        nodelist = self.freqNodeList[node.cnt]
        nodelist.removeNode(node)
        
        if node.cnt == self.minFreq and self.freqNodeList[node.cnt].size == 0:
            self.minFreq += 1
            
        if (node.cnt+1) in self.freqNodeList:
            nextHigherFreqNodeList = self.freqNodeList[node.cnt+1]
        else:
            nextHigherFreqNodeList = NodeList()
            
        node.cnt += 1
        nextHigherFreqNodeList.addFront(node)
        
        self.freqNodeList[node.cnt] = nextHigherFreqNodeList
        self.keyNode[node.key] = node
        

    def get(self, key: int) -> int:
        if key in self.keyNode:
            node = self.keyNode[key]
            ans = node.val
            self.updateFreqNodeList(node)
            
            return ans
        
        else:
            return -1
        

    def put(self, key: int, value: int) -> None:
        if self.maxSizeCache == 0:
            return
        
        if key in self.keyNode:
            node = self.keyNode[key]
            node.val = value
            self.updateFreqNodeList(node)
            return
        
        else:
            if self.currSize == self.maxSizeCache:
                nodelist = self.freqNodeList[self.minFreq]
                del self.keyNode[nodelist.tail.prev.key]
                nodelist.removeNode(nodelist.tail.prev)
                self.currSize -= 1
                
            self.currSize += 1
            self.minFreq = 1
            
            if self.minFreq in self.freqNodeList:
                nodelist = self.freqNodeList[self.minFreq]
            else:
                nodelist = NodeList()
                
            node = Node(key, value)
            nodelist.addFront(node)
            
            self.keyNode[key] = node
            self.freqNodeList[self.minFreq] = nodelist
        


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
