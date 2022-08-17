from bisect import bisect_right
from collections import deque


class Solution:
    def maxProfitAssignment(self, difficulty, profit, worker):
        L = len(difficulty)

        # create sorted difficulty and corresponding maximum profits
        diffs = []
        profs = deque([0])  # reduce profs emtpy judge when using max function

        for diff, prof in sorted((difficulty[i], profit[i]) for i in range(L)):
            diffs.append(diff)
            profs.append(max(profs[-1], prof))

        profs.popleft()  # remove helper dummy head

        # binary search for capable work, and add up max possible profits of that work
        total_profits = 0

        for w in worker:
            idx = bisect_right(diffs, w) - 1
            if idx >= 0: total_profits += profs[idx]

        return total_profits
