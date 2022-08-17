from bisect import bisect_right
class Solution:
    def longestObstacleCourseAtEachPosition(self, obstacles: List[int]) -> List[int]:
        longest, res = [], []
        for i in range(len(obstacles)):
            idx = bisect_right(longest, obstacles[i])
            if idx == len(longest):
                longest.append(obstacles[i])
            else:
                longest[idx] = obstacles[i]
            res.append(idx+1)
        return res
