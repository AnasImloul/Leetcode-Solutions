// Runtime: 4002 ms (Top 5.39%) | Memory: 59.1 MB (Top 9.23%)
class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[0]-x[1])
        def ok(mid):
            for actual, minimum in tasks:
                if minimum > mid or actual > mid: return False
                if minimum <= mid: mid -= actual
            return True
        l, r = 0, 10 ** 9
        while l <= r:
            mid = (l+r) // 2
            if ok(mid): r = mid - 1
            else: l = mid + 1
        return l