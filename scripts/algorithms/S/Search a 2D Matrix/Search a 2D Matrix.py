class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        left=0
        right=len(matrix)-1
        while left <= right:
            mid=(left+right)//2
            if matrix[mid][0] < target:
                left = mid+1
            elif matrix[mid][0] >target:
                right= mid-1
            else:
                return True
        left1=0
        right1=len(matrix[right])-1
        while left1 <= right1:
            mid=(left1+right1)//2
            if matrix[right][mid] < target:
                left1 = mid+1
            elif matrix[right][mid] >target:
                right1= mid-1
            else:
                return True
        return False
