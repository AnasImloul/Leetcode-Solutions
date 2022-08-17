class Solution:
    def assignTasks(self, servers: List[int], tasks: List[int]) -> List[int]:
        servers_available = [(w, i) for i,w in enumerate(servers)]
        heapify(servers_available)
        tasks_in_progress = []
        res = []
        time = 0
        for j,task in enumerate(tasks):
            time = max(time, j)
            if not servers_available:
                time = tasks_in_progress[0][0]
            while tasks_in_progress and tasks_in_progress[0][0] <= time:
                heappush(servers_available, heappop(tasks_in_progress)[1])
            res.append(servers_available[0][1])
            heappush(tasks_in_progress, (time + task, heappop(servers_available)))
        return res
