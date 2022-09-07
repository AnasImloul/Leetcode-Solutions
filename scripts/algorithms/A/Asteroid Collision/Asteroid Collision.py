# Runtime: 217 ms (Top 12.45%) | Memory: 15.1 MB (Top 94.18%)
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:

        res = []

        for asteroid in asteroids:

            while len(res) and asteroid < 0 and res[-1] > 0:

                if res[-1] == -asteroid:
                    res.pop()
                    break
                elif res[-1] < -asteroid:
                    res.pop()
                    continue
                elif res[-1] > -asteroid:
                    break
            else:
                res.append(asteroid)
        return res