# Runtime: 95 ms (Top 82.54%) | Memory: 14.1 MB (Top 72.96%)
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:

        path = []
        answer = []
        def dp(idx, total):
            if total == target:
                answer.append(path[:])
                return
            if total > target:
                return

            for i in range(idx, len(candidates)):
                path.append(candidates[i])
                dp(i, total + candidates[i])
                path.pop()

        dp(0, 0)
        return answer
