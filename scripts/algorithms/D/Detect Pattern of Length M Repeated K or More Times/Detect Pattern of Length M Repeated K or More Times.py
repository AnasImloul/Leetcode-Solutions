class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        if len(arr) < k*m:
            return False
        
        n = len(arr)
        pattern = arr[0:m]
        repeats = 1
        for i in range(m, n - m + 1, m):
            if arr[i:i+m] != pattern:
                break
            
            repeats += 1
            if repeats >= k:
                return True
            
        return self.containsPattern(arr[1:], m, k)