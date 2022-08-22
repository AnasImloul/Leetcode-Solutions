# Runtime: 64 ms (Top 41.88%) | Memory: 14.5 MB (Top 71.25%)
class RLEIterator:

    def __init__(self, encoding: List[int]):
        self.encoding = encoding

    def next(self, n: int) -> int:

        if self.encoding:

            count = self.encoding[0]

            if count >= n:
                # Partially exhaust and return the current value.
                self.encoding[0] -= n
                return self.encoding[1]

            # Exhaust all of current value and continue.
            self.encoding = self.encoding[2:]
            return self.next(n - count)

        return -1