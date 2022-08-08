class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        def helper(idx, reachable):
            if reachable or visited[idx]:
                return reachable
            if arr[idx] == 0:
                reachable = True
                return reachable
            visited[idx] = True
            left, right = idx-arr[idx], idx+arr[idx]
            if left >=0:
                reachable = helper(left,reachable)
            if right < len(arr):
                reachable = helper(right,reachable)
            visited[idx] = False 
            return reachable
        
        visited = [False for _ in arr]
        return helper(start,False)
