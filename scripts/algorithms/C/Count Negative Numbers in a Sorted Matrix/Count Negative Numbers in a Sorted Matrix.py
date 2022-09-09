# Runtime: 252 ms (Top 17.18%) | Memory: 15.1 MB (Top 10.42%)
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0

        for i in grid:
            low = 0
            high = len(i) - 1

            while low <= high:
                mid = (low+high)//2
                if i[mid] < 0:
                    high = mid - 1
                elif i[mid] >= 0:
                    low = mid + 1
            count += (len(i) - low)
        return count