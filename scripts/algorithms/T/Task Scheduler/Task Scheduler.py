class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        max_heap = []
        queue = deque()
        word_count = defaultdict(int)
        timer = 0
        for i in range(len(tasks)):
            word_count[tasks[i]] += 1
        for _ , val in word_count.items():
            heappush(max_heap, -1*val)
        while max_heap or queue:
            timer += 1
            if max_heap:
                v = -1* heappop(max_heap)
                v -= 1
                if v:
                    queue.append((v, timer+n))
            if queue and queue[0][1] == timer:
                heappush(max_heap, -1*queue.popleft()[0])
        return timer
