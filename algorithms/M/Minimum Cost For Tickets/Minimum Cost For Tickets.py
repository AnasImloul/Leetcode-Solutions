class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        min_cost = float('inf')
        que = deque()
        # enqueue the possible state of day 1
        que.append((days[0], costs[0]))
        que.append((days[0]+7-1, costs[1]))
        que.append((days[0]+30-1, costs[2]))
        last_day = days[-1]
        for i in range(1, len(days)):
            for _ in range(len(que)):
                node = que.popleft()
                if node[0] < days[i]:
                    # try taking all the three pass on that day and enqueue 
                    que.append((days[i], node[1]+costs[0]))
                    if days[i] + 7 - 1 >= last_day:
                        min_cost = min(min_cost, node[1] + costs[1])
                    else:
                        que.append((days[i]+7-1, node[1]+costs[1]))
                    if days[i] + 30 - 1 >= last_day: 
                        min_cost = min(min_cost, node[1] + costs[2])
                    else:
                        que.append((days[i]+30-1, node[1]+costs[2]))
                else:
                    que.append(node)
        for _ in range(len(que)):
            node = que.popleft()
            min_cost = min(min_cost, node[1])
        return min_cost
