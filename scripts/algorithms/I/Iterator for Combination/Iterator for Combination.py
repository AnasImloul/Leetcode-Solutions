// Runtime: 54 ms (Top 68.38%) | Memory: 20.00 MB (Top 5.53%)

class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.characters = characters
        self.n = len(characters)
        self.combinations = gen_combinations(self.n, combinationLength)
        self.ind = len(self.combinations) - 1

    def next(self) -> str:
        s = ""
        for i in range(self.n):
            if self.combinations[self.ind][i] != "0":
                s += self.characters[i]
        self.ind -= 1
        return s

    def hasNext(self) -> bool:
        return self.ind > -1 
    
def gen_combinations(l, n):
    end = int("1" * l, 2)
    ans = []
    for i in range(end + 1):
        b = bin(i)[2:]
        if b.count('1') == n:
            ans.append(b.zfill(l))
    return ans
