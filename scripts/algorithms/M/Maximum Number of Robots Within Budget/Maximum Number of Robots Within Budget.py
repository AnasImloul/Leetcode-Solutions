class Solution:
    def maximumRobots(self, chargeTimes, runningCosts, budget):
        from sortedcontainers import SortedList

        running_sum, left, n, ans = 0, 0, len(chargeTimes), SortedList()

        for right in range(n):
            running_sum += runningCosts[right]
            ans.add(chargeTimes[right])
            if ans[-1] + (right-left+1)*running_sum > budget:
                ans.remove(chargeTimes[left])
                running_sum -= runningCosts[left]
                left += 1

        return n - left















