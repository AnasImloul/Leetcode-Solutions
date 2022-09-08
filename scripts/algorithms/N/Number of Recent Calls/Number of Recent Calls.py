# Runtime: 676 ms (Top 17.97%) | Memory: 19.4 MB (Top 70.89%)
class RecentCounter:
    # Here we use list to store ping details.
    def __init__(self):
        self.store = []

    def ping(self, t: int) -> int:
        # Basically what we need to return is how many pings fall in the range(t-3000, t).
        # So here we append every t. Now in loop how many t from left side < t-3000, we just pop them
        # and return the length of the list, which'd contain elements in range(t-3000, t).
        # And since every t is going to greater than previous, we don't need to think about duplicates.

        self.store.append(t)

        while self.store[0] < t-3000:
            self.store.pop(0)

        return len(self.store)