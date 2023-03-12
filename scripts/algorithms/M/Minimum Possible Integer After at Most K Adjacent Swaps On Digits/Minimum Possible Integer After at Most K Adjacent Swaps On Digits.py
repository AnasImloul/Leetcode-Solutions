from sortedcontainers import SortedList

class Solution:
    def minInteger(self, num: str, k: int) -> str:
        sz, window = len(num), SortedList()
        remainedIndices, poppedIndices = SortedList(range(sz)), []
        while k > 0:
            while len(window) < k + 1 and len(window) < len(remainedIndices):
                idx = remainedIndices[len(window)]
                window.add((num[idx], idx))
            if not window:
                break
            index = window.pop(0)[1]
            k -= remainedIndices.bisect_left(index)
            remainedIndices.remove(index)
            poppedIndices.append(index)
            for idx in remainedIndices[k + 1: len(window)]:
                window.remove((num[idx], idx))
        poppedSet = set(poppedIndices)
        return "".join(num[idx] for idx in poppedIndices) + "".join(num[idx] for idx in range(sz) if idx not in poppedSet)