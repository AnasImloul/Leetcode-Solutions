# Runtime: 2 ms (Top 67.19%) | Memory: 19.30 MB (Top 35.94%)

class Solution:
    def removeAlmostEqualCharacters(self, word: str) -> int:

        word = map(ord,word)
        adj_eq, ans = False, 0

        for a,b in pairwise(word):
            if adj_eq or abs(a-b) > 1:
                adj_eq = False
                continue

            adj_eq = True
            ans+= 1

        return ans
