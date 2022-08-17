class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids = sorted(asteroids)
        for i in asteroids:
            if i <= mass:
                mass += i
            else:
                return False
        return True
