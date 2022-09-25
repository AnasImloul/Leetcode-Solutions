# Runtime: 3214 ms (Top 11.47%) | Memory: 41 MB (Top 91.69%)
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
        events = []
        for s, e in flowers:
            heapq.heappush(events, (s,1))
            # Note here should be e+1 since the flowers still count at timepoint e.
            heapq.heappush(events, (e+1,-1))

        flowers = 0
        answer = {}
        for t in sorted(persons):
            while events and events[0][0] <= t:
                _, f = heapq.heappop(events)
                flowers += f
            answer[t] = flowers

        return [answer[i] for i in persons]