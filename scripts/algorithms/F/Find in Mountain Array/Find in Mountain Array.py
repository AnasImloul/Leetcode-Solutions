# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        min_index = -1
        peak = self.findpeak(mountain_arr)
        
        min_index = self.binary_search(0, peak, mountain_arr, target, 1)
        if min_index == -1:
            min_index = self.binary_search(peak+1, mountain_arr.length() - 1, mountain_arr, target, -1)
        return min_index

    def findpeak(self, mountain_arr):
        start = 0
        end = mountain_arr.length() - 1
        while start < end:
            mid = start + int((end - start)/2)
            if mountain_arr.get(mid) < mountain_arr.get(mid + 1):
                start = mid + 1
            else:
                end = mid
        
        return start
    
    def binary_search(self, start, end, mountain_arr, target, asc):
        while start <= end:
            mid = start + int((end - start)/2)
            mountain_arr_get_mid = mountain_arr.get(mid)
            if target == mountain_arr_get_mid:
                return mid
            if asc == 1:
                if target < mountain_arr_get_mid:
                    end = mid - 1
                elif target > mountain_arr_get_mid:
                    start = mid + 1
            else:
                if target < mountain_arr_get_mid:
                    start = mid + 1
                elif target > mountain_arr_get_mid:
                    end = mid - 1
            
        return -1






