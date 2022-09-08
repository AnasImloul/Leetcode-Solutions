# Runtime: 137 ms (Top 11.43%) | Memory: 14.1 MB (Top 36.03%)
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()

        return statistics.mean(arr[int(len(arr)*5/100):len(arr)-int(len(arr)*5/100)])
