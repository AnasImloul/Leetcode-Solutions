# Runtime: 766 ms (Top 22.98%) | Memory: 17.7 MB (Top 39.36%)
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        """

        """

        houses.sort()
        heaters.sort()

        max_radius = -inf

        for house in houses:
            i = bisect_left(heaters, house)

            if i == len(heaters):
                max_radius = max(max_radius, house - heaters[-1])
            elif i == 0:
                max_radius = max(max_radius, heaters[i] - house)
            else:
                curr = heaters[i]
                prev = heaters[i-1]
                max_radius = max(max_radius,min(abs(house - curr), abs(house-prev)))

        return max_radius

    # O(NLOGN)