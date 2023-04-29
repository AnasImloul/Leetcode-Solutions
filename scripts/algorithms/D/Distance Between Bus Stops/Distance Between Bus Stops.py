class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        # switch start and destination if destination is before start
        if start>destination:    
            start,destination=destination,start
        #find minimum for clockwise and counterclockwise direction
        return  min(sum(distance[start:destination]),sum(distance[:start]+distance[destination:]))