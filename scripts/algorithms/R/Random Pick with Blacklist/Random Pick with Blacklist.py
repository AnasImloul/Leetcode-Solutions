# Runtime: 841 ms (Top 10.38%) | Memory: 24.8 MB (Top 56.73%)
class Solution:

    def __init__(self, n: int, blacklist: List[int]):
        self.hashmap={}
        for b in blacklist:
            self.hashmap[b]=-1
        self.length=n-len(blacklist)
        flag=n-1
        for b in blacklist:
            if b<self.length:
                while flag in self.hashmap:
                    flag-=1
                self.hashmap[b]=flag
                flag-=1

    def pick(self) -> int:
        seed=random.randrange(self.length)
        return self.hashmap.get(seed,seed)

# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()