# Runtime: 182 ms (Top 65.24%) | Memory: 20.7 MB (Top 5.08%)
class ExamRoom:

    def __init__(self, n: int):
        self.N = n
        self.pq = []
        self.dict = {}
        self.addSegment(0, self.N - 1)

    def seat(self) -> int:
        start, end, distance = heapq.heappop(self.pq)
        self.dict.pop(start, None) #Remove old segment from dictionary
        self.dict.pop(end, None)

        if start == end:
            position = start

        elif start == 0:
            position = start
            right = self.addSegment(start + 1, end)

        elif end == self.N - 1:
            position = end
            left = self.addSegment(start, end - 1)

        elif end - start == 1: #ONLY ONE PLACE TO PUT
            position = start
            left = self.addSegment(start + 1, end)

        else:
            position = start + (end - start) // 2
            right = self.addSegment(start, position - 1)
            left = self.addSegment(position + 1, end)

        return position

    def leave(self, p: int) -> None:
        left = self.dict.get(p - 1, None)
        right = self.dict.get(p + 1, None)

        new_start = new_end = p

        if left:
            self.removeSegment(left)
            new_start = left.start

        if right:
            self.removeSegment(right)
            new_end = right.end

        self.addSegment(new_start, new_end)

    def addSegment(self, start, end):
            segment = Segment(start, end, self.N)
            self.dict[segment.start] = segment
            self.dict[segment.end] = segment
            heapq.heappush(self.pq, segment)

    def removeSegment(self, segment):
            self.dict.pop(segment.start, None)
            self.dict.pop(segment.end, None)
            self.pq.remove(segment)

class Segment():
    def __init__(self, start, end, N):
        self.start = start
        self.end = end
        self.distance = self.calculateDistance(start, end, N)

    def __lt__(self, other_segment):
        return self.distance > other_segment.distance if self.distance != other_segment.distance else self.start < other_segment.start

    def calculateDistance(self, start, end, N):
        if start == 0:
            return end

        if end == N - 1:
            return end - start

        else:
            return (end - start) // 2

    def __iter__(self):
        return iter((self.start, self.end, self.distance))