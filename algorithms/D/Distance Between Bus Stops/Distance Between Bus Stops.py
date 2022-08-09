class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        total = sum(distance)
        cur = 0
        while start != destination:
            cur += distance[start]
            start = (start+1)%len(distance)
        return min(cur, total-cur)