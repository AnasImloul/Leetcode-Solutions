class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        vis = [0]*len(arr)
        q = deque() 
        q.append(start) 
        while q:
            cur = q.popleft() 
            print(cur)
            vis[cur] = 1
            if arr[cur] == 0:
                return True
            if cur+arr[cur]<len(arr) and vis[cur+arr[cur]] == 0:
                q.append(cur+arr[cur]) 
            if cur-arr[cur]>=0 and vis[cur-arr[cur]] == 0: 
                q.append(cur-arr[cur])  
        return False

            