// Runtime: 483 ms (Top 81.04%) | Memory: 16.60 MB (Top 99.3%)

class Solution:
    def minDifficulty(self, jobDifficulty, days):
        length = len(jobDifficulty)
        if days > length:
            return -1

        min_difficulties = [[float('inf')] * length for _ in range(days)]

        max_diff = 0
        i = 0
        while i <= length - days:
            max_diff = max(max_diff, jobDifficulty[i])
            min_difficulties[0][i] = max_diff
            i += 1

        current_day = 1
        while current_day < days:
            to = current_day
            while to <= length - days + current_day:
                current_job_difficulty = jobDifficulty[to]
                result = float('inf')
                j = to - 1
                while j >= current_day - 1:
                    result = min(result, min_difficulties[current_day - 1][j] + current_job_difficulty)
                    current_job_difficulty = max(current_job_difficulty, jobDifficulty[j])
                    j -= 1
                min_difficulties[current_day][to] = result
                to += 1
            current_day += 1

        return min_difficulties[days - 1][length - 1]



