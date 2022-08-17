class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        if len(arr) < 3:
            return 0
        
        max_up, max_down = [1 for _ in arr], [1 for _ in arr]
        
        for i, x in enumerate(arr):
            if i == 0:
                continue
            if x > arr[i - 1]:
                max_up[i] = max_up[i - 1] + 1
            
        for j, y in reversed(list(enumerate(arr))):
            if j == len(arr) - 1:
                continue
            if y > arr[j + 1]:
                max_down[j] = max_down[j + 1] + 1
                
        return max(
            x + y - 1 if x > 1 and y > 1 else 0 
            for x, y in zip(max_up, max_down)
        )
