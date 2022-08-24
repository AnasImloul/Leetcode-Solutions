// Runtime: 3128 ms (Top 69.37%) | Memory: 47.6 MB (Top 88.14%)
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        current_points = [point for point in points[0]]

        for row in range(1, len(points)):
            # We traverse current_points left to right and store the maximum possible score that the next row can get,
            # taking into account only the elements with indexes [0, col]
            max_col_points = -float("inf")
            for col in range(0, len(current_points)):
                max_col_points = max(max_col_points - 1, current_points[col])
                current_points[col] = max_col_points

            # We traverse current_points right to left and store the maximum possible score that the next row can get,
            # taking into account only the elements with indexes [col, end]
            max_col_points = -float("inf")
            for col in range(len(current_points) - 1, -1, -1):
                max_col_points = max(max_col_points - 1, current_points[col])
                current_points[col] = max_col_points

            # We update current_points, adding the maximum value we can carry over from the previous row to the value
            # contained in the current column of the current row
            for col in range(len(current_points)):
                current_points[col] = points[row][col] + current_points[col]

        return max(current_points)