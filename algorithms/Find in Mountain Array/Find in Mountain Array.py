class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        n = mountain_arr.length()
        #edge case
        if n == 1:
            if mountain_arr.get(0) == target:
                return 0
            return -1
		
		start = 0
        end = n - 1
        while start <= end:
            mid = (start + end) // 2
            if mid == 0:
                start = 1
                continue
            if mountain_arr.get(mid-1) > mountain_arr.get(mid) or mountain_arr.get(mid) > target:
                end = mid - 1
            else:
                start = mid + 1
        if mountain_arr.get(end) == target:
            return end
			
        start = 0
        end = n - 1
        while start <= end:
            mid = (start + end) // 2
            if mountain_arr.get(mid) == target:
                return mid
            if mid == 0:
                start = 1
                continue
            if mountain_arr.get(mid-1) < mountain_arr.get(mid) or mountain_arr.get(mid) > target:
                start = mid + 1
            else:
                end = mid - 1
        
        return -1
