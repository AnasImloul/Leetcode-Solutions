class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        beg = 0
        end = len(arr)-1
        
        while beg <= end:
            mid = (beg+end)//2
            if arr[mid] < arr[mid+1]:
                beg = mid +1
            elif arr[mid] > arr[mid+1]:
                end = mid -1
        return beg
