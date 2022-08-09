class Solution:
    def racecar(self, target: int) -> int:
        q = [(0, 1)]
        steps = 0
        
        while q:
            num = len(q)
            for i in range(num):
                pos, speed = q.pop(0)
                if pos == target:
                    return steps
                q.append((pos+speed, speed*2))
                rev_speed = -1 if speed > 0 else 1
                if (pos+speed) < target and speed < 0 or (pos+speed) > target and speed > 0:
                    q.append((pos, rev_speed))
            steps += 1