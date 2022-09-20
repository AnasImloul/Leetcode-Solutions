# Runtime: 970 ms (Top 9.86%) | Memory: 20.6 MB (Top 59.47%)
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        obs = set(tuple(o) for o in obstacles)
        x = y = a = out = 0
        move = {0:(0,1), 90:(1,0), 180:(0,-1), 270:(-1,0)}
        for c in commands:
            if c == -1:
                a += 90
            elif c == -2:
                a -= 90
            else:
                direction = a % 360
                dx, dy = move[direction]
                for _ in range(c):
                    if (x + dx, y + dy) in obs:
                        break
                    x += dx
                    y += dy
                out = max(out, x**2 + y**2)
        return out