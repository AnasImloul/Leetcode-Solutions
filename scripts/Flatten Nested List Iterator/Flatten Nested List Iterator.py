class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.flattened_lst = self.flattenList(nestedList)
        self.idx = 0
    
    def next(self) -> int:
        if self.idx >= len(self.flattened_lst):
            raise Exception("Index out of bound")
        self.idx += 1
        return self.flattened_lst[self.idx-1]
    
    def hasNext(self) -> bool:
        return self.idx < len(self.flattened_lst)
    
    def flattenList(self, lst):
        flattened_lst = []
        for ele in lst:
            if ele.isInteger():
                flattened_lst.append(ele.getInteger())
            else:
                flattened_lst.extend(self.flattenList(ele.getList()))
        return flattened_lst