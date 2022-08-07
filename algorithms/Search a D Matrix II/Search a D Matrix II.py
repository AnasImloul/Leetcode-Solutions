
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        colToCheck = [x for x in range(len(matrix[0]))]
        for i in range(len(matrix)):
            checkRow = matrix[i]
            checkRow = checkRow[0: colToCheck[-1] + 1]
            search =Solution.binSearch(self,checkRow, target)
            if search[1] == 1:
                return True # correct
            elif search[0] == 0:
                break
            else:
                colToCheck = colToCheck[0: search[0]+1]



        return False






    def binSearch(self, nums, target):

        leftPointer = 0
        rightPointer = len(nums) -1
        leftOrRight = 0
        while leftPointer <= rightPointer:

            check = int((leftPointer + rightPointer) /2)

            if nums[check] == target:
                return [check, 1]
            elif nums[check] > target:
                rightPointer = check -1 
                leftOrRight = -1
            elif nums[check] < target:
                leftPointer = check + 1
                leftOrRight = 1

        if leftOrRight == 1: # last move was left pointer increase
            return [leftPointer, -1]
        elif leftOrRight == -1:
            return [rightPointer + 1, -1]



