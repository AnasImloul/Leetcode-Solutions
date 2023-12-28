// Runtime: 990 ms (Top 43.31%) | Memory: 53.60 MB (Top 12.36%)

class Solution:
    from collections import defaultdict, deque
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        # Base case
        if source == target:
            return 0
        # Creating graph or routes
        graph = defaultdict(set)
        
        # Since index represents bus_number on a route
        # suppose i is bus number and stops are the values present at that index
        for bus_number, stops in enumerate(routes):
            # for each stop adding buses going to that stop
            for stop in stops:
                graph[stop].add(bus_number)
        
        # Using bfs
        bfs = deque([(source, 0)])
        
        # visited stops 
        seen_stops = set()
        # visited buses
        seen_buses = set()
        
        while bfs:
            stop, count = bfs.popleft()
            # Resulting case
            if stop == target:
                    return count
                
            # Since our graph stores all buses going to a stop
            # We will iterate for every bus
            for bus_number in graph[stop]:
                # We dont want to travel in same bus as we might stuck into loop and reach nowhere
                if bus_number not in seen_buses:
                    seen_buses.add(bus_number)
                    
                    # Now we are in a bus, so we will travel all the stops that bus goes to but again, we only want to go to stops we haven't visited
                    for stop in routes[bus_number]:
                        if stop not in seen_stops:
                            seen_stops.add(stop)
                            bfs.append((stop, count + 1))
        return -1
