class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        m = defaultdict(set)
        for i, route in enumerate(routes):
            for node in route:
                m[node].add(i)
        ans = -1
        vis = set()
        queue = deque()
        queue.append(source)
        while queue:
            l = len(queue)
            ans += 1
            for _ in range(l):
                cur = queue.popleft()
                if cur == target:
                    return ans
                for bus in m[cur]:
                    if bus not in vis:
                        vis.add(bus)
                        queue.extend(routes[bus])
        return -1
