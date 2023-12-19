// Runtime: 1313 ms (Top 92.99%) | Memory: 41.50 MB (Top 72.32%)

class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        Arr = [0] * n  # i-th city has Arr[i] roads
        for A,B in roads:
            Arr[A] += 1 # Each road increase the road count
            Arr[B] += 1
        Arr.sort()  # Cities with most road should receive the most score
        summ = 0
        for i in range(len(Arr)):
            summ += Arr[i] * (i+1)  # Multiply city roads with corresponding score
        
        return summ
