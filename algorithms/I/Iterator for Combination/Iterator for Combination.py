class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        res = []
        def dfs(low, path):
            if len(path) == combinationLength:
                res.append(path)
                return
            for idx in range(low, len(characters)):
                dfs(idx+1, path+characters[idx])
        
        dfs(0, "")
        self.combinations = res
        self.currIdx = 0
            
    def next(self) -> str:
        self.currIdx += 1
        return self.combinations[self.currIdx-1]

    def hasNext(self) -> bool:
        return self.currIdx <= len(self.combinations) - 1
