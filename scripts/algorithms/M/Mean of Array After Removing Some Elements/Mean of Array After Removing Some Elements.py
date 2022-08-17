class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()

        return statistics.mean(arr[int(len(arr)*5/100):len(arr)-int(len(arr)*5/100)])
        
