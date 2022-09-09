# Runtime: 441 ms (Top 30.19%) | Memory: 23.9 MB (Top 87.19%)
from collections import defaultdict
class UndergroundSystem:
    def __init__(self):
        self.checkin = {}
        self.traveltime = defaultdict(dict)

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkin[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation, startTime = self.checkin[id]
        del self.checkin[id]
        if stationName not in self.traveltime[startStation]:
            self.traveltime[startStation][stationName] = []
        self.traveltime[startStation][stationName].append(t-startTime)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        return sum(self.traveltime[startStation][endStation])/len(self.traveltime[startStation][endStation])