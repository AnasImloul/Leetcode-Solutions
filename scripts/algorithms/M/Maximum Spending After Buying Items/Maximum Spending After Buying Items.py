# Runtime: 194 ms (Top 20.88%) | Memory: 28.20 MB (Top 96.70%)

class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        heap = []
        heapify(heap)

        for i, shop in enumerate(values):
            heappush(heap, (shop.pop(), i))

        day, spent = 1, 0

        while heap:
            item = heappop(heap)

            spent += item[0] * day

            if len(values[item[1]]) > 0:
                heappush(heap, (values[item[1]].pop(), item[1]))

            day += 1

        return spent
