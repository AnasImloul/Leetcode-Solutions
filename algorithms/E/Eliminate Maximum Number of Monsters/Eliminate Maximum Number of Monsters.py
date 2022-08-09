class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        for i, t in enumerate(sorted([(d - 1) // s for d, s in zip(dist, speed)])):
            if i > t:
                return i
        return len(dist)  
