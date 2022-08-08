class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def neighbor(s):
            res = []
            for i, c in enumerate(s):
                res.append(s[:i] + chr((ord(c) - ord('0') + 9) % 10 + ord('0')) + s[i + 1:])
                res.append(s[:i] + chr((ord(c) - ord('0') + 1) % 10 + ord('0')) + s[i + 1:])
            return res
        
        deadends = set(deadends)
        if "0000" in deadends:
            return -1
        ans = 0
        queue = deque(["0000"])
        vis = set()
        while queue:
            l = len(queue)
            for _ in range(l):
                cur = queue.popleft()
                if cur == target:
                    return ans
                for nxt in neighbor(cur):
                    if nxt not in vis and nxt not in deadends:
                        queue.append(nxt)
                        vis.add(nxt)
            ans += 1
        return -1
