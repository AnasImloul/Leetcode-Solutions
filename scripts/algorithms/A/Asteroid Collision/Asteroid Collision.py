# Runtime: 103 ms (Top 70.1%) | Memory: 17.56 MB (Top 44.2%)

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for a in asteroids:
            while stack and stack[-1] > 0 > a:
                if stack[-1] < abs(a):
                    stack.pop()
                    continue
                elif stack[-1] == abs(a):
                    stack.pop()
                break # this means asteroid must be destroyed (not add to stack in else statement below)
            else:
                stack.append(a)
        
        return stack