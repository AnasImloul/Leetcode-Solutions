# Runtime: 93 ms (Top 33.43%) | Memory: 14.1 MB (Top 44.38%)
class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        result = 0
        curCap = capacity

        for i in range(len(plants)):
            if curCap >= plants[i]:
                curCap -= plants[i]
                result += 1

            else:
                result += i * 2 + 1
                curCap = capacity - plants[i]

        return result