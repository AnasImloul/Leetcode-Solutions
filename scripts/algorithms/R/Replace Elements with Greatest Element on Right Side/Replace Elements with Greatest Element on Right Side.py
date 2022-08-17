class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        maxright = arr[-1]
        for i in range(len(arr) -1,-1,-1):
            temp = arr[i]
            arr[i] = maxright
            if temp > maxright:
                maxright = temp
        arr[-1] = -1
        
        return arr
