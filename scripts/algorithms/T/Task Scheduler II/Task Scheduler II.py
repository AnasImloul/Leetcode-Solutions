# Runtime: 2321 ms (Top 5.03%) | Memory: 29.8 MB (Top 75.04%)
import math
class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        count_dict = {}
        total_days = 0
        for task in tasks:
            if task not in count_dict:
                count_dict[task] = -math.inf
            total_days = max(total_days + 1, count_dict[task] + space + 1)
            count_dict[task] = total_days
        return total_days