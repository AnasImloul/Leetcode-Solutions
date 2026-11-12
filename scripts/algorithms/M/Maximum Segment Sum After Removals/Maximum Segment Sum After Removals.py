# Runtime: 180 ms (Top 65.08%) | Memory: 55.50 MB (Top 23.81%)

class Solution:
    def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
        mp, cur, res = {}, 0, []
        for q in reversed(removeQueries[1:]):
            mp[q] = (nums[q], 1)
            rv, rLen = mp.get(q+1, (0, 0))
            lv, lLen = mp.get(q-1, (0, 0))

            total = nums[q] + rv + lv
            mp[q+rLen] = (total, lLen + rLen + 1)
            mp[q-lLen] = (total, lLen + rLen + 1)

            cur = max(cur, total)
            res.append(cur)

        return res[::-1] + [0]
