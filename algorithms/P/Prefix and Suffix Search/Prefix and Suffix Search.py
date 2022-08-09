class WordFilter:
    def __init__(self, words: List[str]):
        self.words = words
        
    def f(self, prefix: str, suffix: str) -> int:
        idx = -1
        for i,w in enumerate(self.words):
            if w.startswith(prefix) and w.endswith(suffix):
                idx = i
        
        return idx

