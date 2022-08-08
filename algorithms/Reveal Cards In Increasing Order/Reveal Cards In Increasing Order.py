class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        reveal=deque()
        deck.sort()
        while deck:
            reveal.rotate()
            reveal.appendleft(deck.pop())
        return reveal
 
