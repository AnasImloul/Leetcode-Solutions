class Solution:
    def createTargetArray(self, nums, index):
        
        def merge(arr, low, mid, high):
            L, R = arr[low:mid+1], arr[mid+1:high+1]
            i = j = 0
            k = low
            
            while i < len(L) and j < len(R):
                if L[i][0] + j >= R[j][0]:
                    arr[k] = R[j]
                    j += 1
                else:
                    L[i][0] += j
                    arr[k] = L[i]
                    i += 1
                k += 1
            
            while i < len(L):
                L[i][0] += j
                arr[k] = L[i]
                i += 1; k += 1
                
            while j < len(R):
                arr[k] = R[j]
                j += 1; k += 1
            
        
        def mergeSort(arr, low, high):
            if low < high:
                mid = (low + high) // 2
                mergeSort(arr, low, mid)
                mergeSort(arr, mid + 1, high)
                merge(arr, low, mid, high)
                
        arr = [[index[i], nums[i]] for i in range(len(nums))]
        mergeSort(arr, 0, len(nums) - 1)
        
        for x in arr:
            nums[x[0]] = x[1]
        
        return nums