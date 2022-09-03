# Runtime: 574 ms (Top 47.47%) | Memory: 28.9 MB (Top 58.47%)
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        diff=float(inf)
        for i in range(0,len(arr)-1):
            if arr[i+1]-arr[i]<diff:
                diff=arr[i+1]-arr[i]
        lst=[]
        for i in range(0,len(arr)-1):
            if arr[i+1]-arr[i]==diff:
                lst.append([arr[i],arr[i+1]])
        return lst
