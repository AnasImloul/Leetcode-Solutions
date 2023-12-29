// Runtime: 68 ms (Top 91.63%) | Memory: 20.60 MB (Top 5.75%)

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # Convert time points to minutes since midnight and sort the list
        minutes = sorted([int(time[:2]) * 60 + int(time[3:]) for time in timePoints])
        
        # Calculate the minimum difference between adjacent time points
        min_diff = float('inf')
        for i in range(len(minutes) - 1):
            diff = minutes[i+1] - minutes[i]
            if diff < min_diff:
                min_diff = diff
        
        # Calculate the difference between the first and last time points
        diff = (24*60 - minutes[-1] + minutes[0]) % (24*60)
        if diff < min_diff:
            min_diff = diff
        
        return min_diff

