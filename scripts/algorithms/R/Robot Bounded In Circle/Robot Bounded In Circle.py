# Runtime: 34 ms (Top 89.04%) | Memory: 14 MB (Top 22.71%)

class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        pos, d = [0,0], "N"
        def move(d, pos, instructions):
            for i in instructions:
                if i == "G":
                    if d == "N": pos[1] += 1
                    elif d == "S": pos[1] -= 1
                    elif d == "W": pos[0] -= 1
                    else: pos[0] += 1
                elif i == "L":
                    if d == "N": d = "W"
                    elif d == "W": d = "S"
                    elif d == "S": d = "E"
                    else: d = "N"
                else:
                    if d == "N": d = "E"
                    elif d == "W": d = "N"
                    elif d == "S": d = "W"
                    else: d = "S"
            return (d, pos)
        for i in range(4):
            d, pos = (move(d, pos, instructions))
        return True if pos == [0,0] else False