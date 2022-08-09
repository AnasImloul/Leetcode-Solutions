class Solution:
    def findLucky(self, arr: List[int]) -> int:
        dc = {}
        
        for i in range(len(arr)):
            if arr[i] not in dc:
                dc[arr[i]] = 1
            else:
                dc[arr[i]] = dc[arr[i]] + 1
        mx = -1
        for key,value in dc.items():
            if key == value:
                mx = max(key, mx)
        return mx
