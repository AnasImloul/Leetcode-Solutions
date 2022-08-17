class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        out=[]
        for i, j in zip(l, r):
            out.append(self.canMakeArithmeticProgression(nums[i:j+1]))
        return out
        
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        minArr = min(arr)
        maxArr = max(arr)
		
		# if difference between minArr and maxArr cannot be divided into equal differences, then return false
        if (maxArr-minArr)%(len(arr)-1)!=0:
            return False
			
		# consecutive difference in arithmetic progression
        diff = int((maxArr-minArr)/(len(arr)-1))
        if diff == 0:
            if arr != [arr[0]]*len(arr):
                return False
            return True
		
		# array to check all numbers in A.P. are present in input array.
		# A.P.[minArr, minArr+d, minArr+2d, . . . . . . . maxArr]
        check = [1]*len(arr)
        for num in arr:
            if (num-minArr)%diff != 0:
                return False
            check[(num-minArr)//diff]=0
		
		# if 1 is still in check array it means at least one number from A.P. is missing from input array.
        if 1 in check:
            return False
        return True
