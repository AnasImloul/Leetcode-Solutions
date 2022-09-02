# Runtime: 5727 ms (Top 5.11%) | Memory: 14.3 MB (Top 62.50%)
class Solution(object):
    def bestTeamScore(self, scores, ages):
        """
        :type scores: List[int]
        :type ages: List[int]
        :rtype: int
        """
        l = len(scores)
        mapped = [[ages[i], scores[i]] for i in range(l)]
        mapped = sorted(mapped, key = lambda x : (x[0], x[1]))
        dp = [i[1] for i in mapped]

        for i in range(l):
            for j in range(0, i):
                if mapped[j][1] <= mapped[i][1]:
                    dp[i] = max(dp[i], mapped[i][1] + dp[j])
                elif mapped[i][0] == mapped[j][0]:
                    dp[i] = max(dp[i], mapped[i][1] + dp[j])

        return max(dp)