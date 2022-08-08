class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        """
            Eqn is: yi + yj + |xi - xj|
            Since points is sorted by x values, 
                therefore, xj will always be greater than xi
                therefore xi - xj will always be negative
            So the above eqn can be rewritten as,
                (yj+xj) + (yi-xi)
            Now the problem boils down to finding maximum in sliding window of k size.
            (https://leetcode.com/problems/sliding-window-maximum/discuss/1911533/Python-or-Dequeue-or-Sliding-Window-or-Simple-Solution)
        """
        queue = deque()
        maxVal = -sys.maxsize
        for x,y in points:
            while queue and abs(queue[0][0] - x) > k:
                queue.popleft()
            
            if queue:
                maxVal = max(maxVal, y+x+queue[0][1])
            
            while queue and queue[-1][1] <= y-x:
                queue.pop()
            
            queue.append((x, y-x))
            
        return maxVal
