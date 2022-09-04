# Runtime: 2207 ms (Top 14.71%) | Memory: 27.8 MB (Top 42.78%)
class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids = sorted(asteroids)
        for i in asteroids:
            if i <= mass:
                mass += i
            else:
                return False
        return True