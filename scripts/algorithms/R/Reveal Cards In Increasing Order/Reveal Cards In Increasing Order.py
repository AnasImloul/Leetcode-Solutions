# Runtime: 73 ms (Top 54.69%) | Memory: 14.1 MB (Top 45.76%)
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        reveal=deque()
        deck.sort()
        while deck:
            reveal.rotate()
            reveal.appendleft(deck.pop())
        return reveal
