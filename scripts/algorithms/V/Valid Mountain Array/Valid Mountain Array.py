# Runtime: 391 ms (Top 35.19%) | Memory: 15.5 MB (Top 21.40%)
class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return False
        for i in range(1,len(arr)):
            if arr[i] <= arr[i-1]:
                if i==1:
                    return False
                break

        for j in range(i,len(arr)):
            if arr[j] >= arr[j-1]:
                return False
        return True