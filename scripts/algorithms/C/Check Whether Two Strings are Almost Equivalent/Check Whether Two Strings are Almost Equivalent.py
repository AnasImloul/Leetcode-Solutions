class Solution:
    def checkAlmostEquivalent(self, w1: str, w2: str) -> bool:
		return all(v < 4 for v in ((Counter(w1) - Counter(w2)) + (Counter(w2) - Counter(w1))).values())
