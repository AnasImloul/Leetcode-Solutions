# Runtime: 1570 ms (Top 45.22%) | Memory: 36.4 MB (Top 42.14%)
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        def computeArrivalTime(curr_pos, curr_speed):
            nonlocal target
            return (target - curr_pos) / curr_speed
            # avoid integer division, as a car may arrive at 5.2s and another at 5.6s

        cars = list(zip(position, speed))
        cars.sort(key=lambda x: x[0], reverse=True)
        arrival_bound = None # time upper bound
        fleet = 0
        for pos, sp in cars:
            curr_arrival = computeArrivalTime(pos, sp)
            if not arrival_bound or curr_arrival > arrival_bound:
                arrival_bound = curr_arrival
                fleet += 1
        return fleet
    # time O(n logn): sort = (nlogn); loop = (n)
    # space O(n): depend on sort