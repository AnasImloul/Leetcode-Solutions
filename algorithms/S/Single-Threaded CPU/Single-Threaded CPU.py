class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        # For better readability
        Task = namedtuple('Task', ['etime', 'ptime', 'index'])
        
        # Sort the tasks by enqueue time, shortest processing time and index
        stasks = sorted([Task(task[0], task[1], i) for i, task in enumerate(tasks)])
        # t: current CPU clock; i: current task index
        t = i = 0
        heap, result = [], []
        
        while len(result) < len(stasks):
            # Push all the tasks available at current CPU clock
            while i < len(stasks) and stasks[i].etime <= t:
                heappush(heap, (stasks[i].ptime, stasks[i].index))
                i += 1
            if heap:
                ptime, index = heappop(heap)
                result.append(index)
                t += ptime
            else:
                # Jump to the next available task
                t = stasks[i].etime
        return result
