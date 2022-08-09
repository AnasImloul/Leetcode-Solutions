class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        queue = deque([(0,1)])
        jumps = 0
        forbidden = set(forbidden)
        forbidden.add(0)
        MAX_DIST = max(x, max(forbidden)) + a + b
        while queue:
            tmp = deque()
            for elem in queue:
                (pos, direction) = elem
                if pos == x: return jumps
                forward = pos + a
                if forward not in forbidden and forward <= MAX_DIST:
                    tmp.append((forward, 1))
                    forbidden.add(forward)
            for elem in queue:
                (pos, direction) = elem
                if pos == x: return jumps
                backward = pos - b
                if direction != -1 and backward >= 0 and backward not in forbidden:
                    tmp.append((backward, -1))
                    forbidden.add(backward)
            queue = tmp
            jumps += 1
        return -1
