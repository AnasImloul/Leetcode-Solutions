// Runtime: 153 ms (Top 95.7%) | Memory: 18.70 MB (Top 43.81%)

class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr)<=2 or max(arr)==arr[0] or max(arr)==arr[len(arr)-1]:
            return False
        f=True
        for i in range(len(arr)-1):
            if f and arr[i]>=arr[i+1]:
                f=False
            if not f and arr[i]<=arr[i+1]:
                return False
        return True
