class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        boxes = [0] * 100
        
        for i in range(lowLimit, highLimit + 1):
			
			# For the current number "i", convert it into a list of its digits.
			# Compute its sum and increment the count in the frequency table.
			
            boxes[sum([int(j) for j in str(i)])] += 1
        
        return max(boxes)