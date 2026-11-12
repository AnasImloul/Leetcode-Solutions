# Runtime: 819 ms (Top 5.03%) | Memory: 56.70 MB (Top 97.38%)

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        ans = [0] * n
        times = [0] * n
        meetings.sort()

        for start, end in meetings:
            flag = False
            minind = -1
            val = float('inf')
            for j in range(n):
                if times[j] < val:
                    val = times[j]
                    minind = j
                if times[j] <= start:
                    flag = True
                    ans[j] += 1
                    times[j] = end
                    break
            if not flag:
                ans[minind] += 1
                times[minind] += (end - start)

        maxi = -1
        id = -1
        for i in range(n):
            if ans[i] > maxi:
                maxi = ans[i]
                id = i
        return id
