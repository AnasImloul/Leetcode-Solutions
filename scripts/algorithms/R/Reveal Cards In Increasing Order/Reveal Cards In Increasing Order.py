# Runtime: 61 ms (Top 23.0%) | Memory: 16.70 MB (Top 8.0%)

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        def reveal(n):
            lst = list(range(n))
            ans = []
            i = 0
            while lst:
                if not i&1: ans.append(lst.pop(0))
                else: lst.append(lst.pop(0))
                i += 1
            return ans
        ans = reveal(len(deck))
        ans = sorted([v, i] for i, v in enumerate(ans))
        deck.sort()
        return (deck[j] for i,j in ans)