# Runtime: 1058 ms (Top 6.78%) | Memory: 15.2 MB (Top 89.63%)
class Solution:
    def maxArea(self,arr: List[List[int]]) -> int:
        maxA = 0 #local max variable to return max area of a 1D array
        stack = [-1] #initializing with minimum value so we can avoid using loop for remaining element in the stack after whole traversing
        arr.append(-1) # value for stack index -1 and one extra iteration to empty the stack
        for i in range(len(arr)): # traversing for stack from left to right
            arr[i] = int(arr[i]) # we are getting str value from matrix
            while stack and arr[stack[-1]] >= int(arr[i]): #stack is non empty and stack top is greater or equal to current element
                index = stack.pop() #pop greater element from stack and finds its area
                width = i - stack[-1] - 1 if stack else i # for empty stack width is len of 1D arr, and after poping if we have element in stack then it becomes left boundary and current index as right boundary
                maxA = max(maxA, width * arr[index]) # geting max area (L * B)
            stack.append(int(i)) # inserting each element in stack
        return maxA # return the max area
    """Below is the code for adding each row one by one and passing it to above function to get the max area for each row"""
    # r1 - 1 0 1 0 0
    # r2 - 1 0 1 1 1
    # r = 2 0 2 1 1 This is for else condition

    # r1 - 1 1 1 0 1
    # r2 - 1 0 1 1 0
    # r = 2 0 2 1 0 This is for if condition

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        result = [0] * len(matrix[0])
        maxReact = 0
        maxReact = self.maxArea(result)
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                matrix[i][j] = int(matrix[i][j])
                if matrix[i][j] == 0:
                    result[j] = 0
                else:
                    result[j] = result[j] + matrix[i][j]
            maxReact = max(maxReact,self.maxArea(result)) #after getting max area for 1D arr we are getting max value from those 1D arr for the 2D arr
        return maxReact
