# Runtime: 162 ms (Top 33.91%) | Memory: 15.3 MB (Top 22.09%)
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        scores_ids = []
        for i in range(len(score)):
            scores_ids.append((score[i], i))
        scores_ids.sort(reverse=True)

        ans = [0] * len(scores_ids)
        for i in range(len(scores_ids)):
            ans[scores_ids[i][1]] = str(i+1)

        try:
            ans[scores_ids[0][1]] = "Gold Medal"
            ans[scores_ids[1][1]] = "Silver Medal"
            ans[scores_ids[2][1]] = "Bronze Medal"
        except:
            pass

        return ans
