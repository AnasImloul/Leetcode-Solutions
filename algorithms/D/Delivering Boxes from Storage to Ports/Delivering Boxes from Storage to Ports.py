class Solution:
    def boxDelivering(self, boxes: List[List[int]], portsCount: int, maxBoxes: int, maxWeight: int) -> int:
        n = len(boxes)
        que = collections.deque([(-1,0)])  # monotonic queue. item: (division_position, trip_cost)
        pre = -1  # latest end of previous trip
		ws = 0  # maximal weights of current trip
        for i, (p, w) in enumerate(boxes):  # p: port; w: weight
            # update the earliest possible start of current trip:
            ws += w
            while i - pre > maxBoxes or ws > maxWeight:
                pre += 1
                ws -= boxes[pre][1]
            while que[0][0] < pre: que.popleft()  ## pop out the boxes out of range of current trip
            
            # min cost of current trip. front of monotonic queue is always the minimal cost that meets the limitation
            mn = (2 if i+1<n and p==boxes[i+1][0] else 1) + que[0][1]
            while que[-1][1] >= mn: que.pop()  # maintain the queue monotonic
            que.append((i, mn))
        
        base_trip = 1  # calc base trip cost
        for i in range(n-1):
            if boxes[i][0] != boxes[i+1][0]: base_trip += 1
        
        return base_trip + que[-1][1]
