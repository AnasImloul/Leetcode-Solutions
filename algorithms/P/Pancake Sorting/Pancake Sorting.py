class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        #helper function to flip the numbers in the array
		def flip(i, j):
            while i < j:
                arr[i], arr[j] = arr[j], arr[i]
                j -= 1
                i += 1
        
        #sort from 0 to i
        def sort(i):
			#base case where all the numbers are sorted, thus no more recursive calls
            if i < 0:
                return []
            ret = []
			#find the biggest number, which always will be the len(arr), or i + 1
            idx = arr.index(i + 1)
			# if the biggest number is in the right place, as in idx == i, then we don't change anything, but just move to sort the next biggest number
            if idx == i:
                return sort(i - 1)
            
			#we flip it with the first element (even if the biggest number is the first element, it will flip itself (k = 1) and does not affect the result
            ret.append(idx + 1)
            flip(0, idx)
			#we know the biggest number is the first element of the array. Flip the whole array in the boundary so that the biggest number would be in the last of the subarray (notice not len(arr) - 1 because that will flip the already-sorted elements as well)
            ret.append(i + 1)
            flip(0, i)
			#sort the next biggest number by setting a new boundary i - 1
            return ret + sort(i - 1)
            
            
        return sort(len(arr) - 1)
            
