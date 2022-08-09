###########################################################################################
#   Runtime: O(MN)
#       Number of rows(M) x expected numbers(N)
#   Space: O(N)
#       We need to store the expected numbers in list
############################################################################################
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        # Validate Input
        if not matrix or not matrix[0]:
            return False                
        
        # Create a deque tracking the expected values for the next row
        expected = matrix[0]
        # We only care about the elements before last element
        expected.pop()
        
        # From the second row, pop out the last element of the expected numbers and compare it with the target row[1:]
        for row in matrix[1:]:
            # Compare row with expected numbers, invalidate it as soon as we find the numbers are not the same (O(N))
            if row[1:] != expected:
                return False
            else:
                # Pop the last element from row, use it as the expected numbers for the next iteration
                row.pop()
                expected = row
        # If we've reached here, all diagonals aligned
        return True
