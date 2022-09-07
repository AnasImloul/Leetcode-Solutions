# Runtime: 354 ms (Top 28.01%) | Memory: 13.9 MB (Top 55.93%)
import heapq
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        h1, h2, h3 = [], [], []
        heapq.heappush(h1, 1)
        heapq.heappush(h2, 1)
        heapq.heappush(h3, 1)
        ugly_number = 1
        last_ugly_number = 1
        count = 1
        while count < n:
            if 2 * h1[0] <= 3 * h2[0] and 2 * h1[0] <= 5 * h3[0]:
                # pop from h1
                x = heapq.heappop(h1)
                ugly_number = 2 * x
                if ugly_number == last_ugly_number:
                    # do nothing
                    continue
                count+=1
                last_ugly_number = ugly_number
                heapq.heappush(h1, ugly_number)
                heapq.heappush(h2, ugly_number)
                heapq.heappush(h3, ugly_number)

            elif 3 * h2[0] <= 2 * h1[0] and 3 * h2[0] <= 5 * h3[0]:
                # pop from h2
                x = heapq.heappop(h2)
                ugly_number = 3 * x
                if ugly_number == last_ugly_number:
                    continue
                count+=1
                last_ugly_number = ugly_number
                heapq.heappush(h1, ugly_number)
                heapq.heappush(h2, ugly_number)
                heapq.heappush(h3, ugly_number)
            else:
                # pop from h3
                x = heapq.heappop(h3)
                ugly_number = 5 * x
                if ugly_number == last_ugly_number:
                    continue
                count+=1
                last_ugly_number = ugly_number
                heapq.heappush(h1, ugly_number)
                heapq.heappush(h2, ugly_number)
                heapq.heappush(h3, ugly_number)

        return last_ugly_number