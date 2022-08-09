class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        
        def sorted_distance(value, static_input = x):
            return abs(value - static_input)
        
        distances = []
        result = []
        heapq.heapify(distances)
        
        for l,v in enumerate(arr):
            distances.append((l, sorted_distance(value = v)))
        
        for i in heapq.nsmallest(k, distances, key = lambda x: x[1]):
            result.append(arr[i[0]])
        
        result.sort()
        return result
            
            
