class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        n = len(arr)
        sorted_arr = []
        for i in range(n):
            sorted_arr.append((arr[i], i))
        sorted_arr.sort(reverse = True)
        depth = [1 for i in range(n)]
        while(sorted_arr):
            val, i = sorted_arr.pop()
            for j in range(i-1, max(-1, i-d-1), -1):
                if(arr[j] >= arr[i]):
                    break
                depth[i] = max(depth[j] + 1, depth[i])
            for j in range(i+1, min(n, i+d+1)):
                if(arr[j] >= arr[i]):
                    break
                depth[i] = max(depth[j] + 1, depth[i])
        return max(depth)
