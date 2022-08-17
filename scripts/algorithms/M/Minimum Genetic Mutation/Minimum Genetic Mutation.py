class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        q = deque()
        q.append(start)
        n = len(bank)
        last = 0
        used = [False] * n
        for i, x in enumerate(bank):
            if start == x:
                used[i] = True
            if end == x:
                last = i
        dist = 0
        while q:
            dist += 1
            for _ in range(len(q)):
                w = q.popleft()
                for i, x in enumerate(bank):
                    if used[i]:
                        continue
                    bad = 0
                    for j in range(8):
                        if w[j] != x[j]:
                            bad += 1
                            if bad == 2:
                                break
                    if bad == 1:
                        if last == i:
                            return dist
                        used[i] = True
                        q.append(x)
        return -1
