class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s1, s2 = sorted(s1), sorted(s2)
        return all(a1 >= a2 for a1, a2 in zip(s1, s2)) or all(a1 <= a2 for a1, a2 in zip(s1, s2))
