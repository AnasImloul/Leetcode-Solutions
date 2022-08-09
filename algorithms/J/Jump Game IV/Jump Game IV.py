from collections import deque
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        minSteps = 0
        queue = deque()
        queue.append(0)
        n = len(arr)
        visited = set()
        visited.add(0)
        
		d = {i:[] for i in arr}
        
        for i, val in enumerate(arr):
            d[val].append(i)
        
        while queue:
            for _ in range(len(queue)):
                idx = queue.popleft()
                if idx == n - 1:
                    return minSteps
                
                for i in [*d[arr[idx]], idx - 1, idx + 1]:
                    if i not in visited and 0 <= i < n:
                        visited.add(i)
                        queue.append(i)
                d[arr[idx]].clear()
            minSteps += 1
