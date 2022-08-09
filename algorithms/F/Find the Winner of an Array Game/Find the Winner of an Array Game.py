class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        if k == 1:
            return max(arr[0], arr[1])
        
        i = wins = 0
        for j in range(1, len(arr)):
            if arr[i] > arr[j]:
                wins += 1
                if wins == k:
                    return arr[i]
            else:
                i = j
                wins = 1
        
        return max(arr)