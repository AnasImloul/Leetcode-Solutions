class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        map_ = {}
        for word in words:
            for i in word:
                if i not in map_:
                    map_[i] = 1
                else:
                    map_[i] += 1
        n = len(words)
        for k,v in map_.items():
            if (v%n) != 0:
                return False
        return True
