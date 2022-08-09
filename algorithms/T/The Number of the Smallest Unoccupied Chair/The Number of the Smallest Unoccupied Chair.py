class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        arrivals = []
        departures = []
        for ind, (x, y) in enumerate(times):
            heappush(arrivals, (x, ind))
            heappush(departures, (y, ind))
        d = {}
        occupied = [0] * len(times)
        while True:
            if arrivals and departures and arrivals[0][0] < departures[0][0]:
                _, ind = heappop(arrivals)
                d[ind] = occupied.index(0)
                occupied[d[ind]] = 1
                if ind == targetFriend:
                    return d[ind]
            elif arrivals and departures and arrivals[0][0] >= departures[0][0]:
                _, ind = heappop(departures)
                occupied[d[ind]] = 0
