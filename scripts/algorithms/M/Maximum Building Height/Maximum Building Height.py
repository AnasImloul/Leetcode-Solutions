// Runtime: 1203 ms (Top 88.37%) | Memory: 55.60 MB (Top 9.3%)

#Readability version
class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        # Set the initial height for the 1st building
        restrictions.append([1, 0])
        restrictions.sort()

        # Process restrictions to find the valid ones for reaching previous restrictions
        valid_restrictions_forward = []
        temp_diff = 0
        for id, ht in restrictions:
            current_diff = id - ht
            if current_diff >= temp_diff:
                temp_diff = current_diff
                valid_restrictions_forward.append([id, ht])

        # Process valid restrictions backward to find the ones for reaching next restrictions
        valid_restrictions_backward = []
        temp_sum = n + n - 1
        for id, ht in valid_restrictions_forward[::-1]:
            current_sum = id + ht
            if current_sum <= temp_sum:
                temp_sum = current_sum
                valid_restrictions_backward.append([id, ht])

        # Reverse the backward valid restrictions to get the correct order
        valid_restrictions_backward.reverse()

        # Add maximum height for the last building due to the last restriction
        if valid_restrictions_backward[-1][0] != n:
            valid_restrictions_backward.append([n, valid_restrictions_backward[-1][1] + n - valid_restrictions_backward[-1][0]])

        # Calculate the maximum height
        max_height = 0
        for i in range(len(valid_restrictions_backward) - 1):
            x1, y1 = valid_restrictions_backward[i]
            x2, y2 = valid_restrictions_backward[i + 1]
            available_height = (-x1 + y1 + x2 + y2) // 2
            if available_height > max_height:
                max_height = available_height

        return max_height

