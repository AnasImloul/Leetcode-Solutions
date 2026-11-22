# Runtime: 79 ms (Top 43.18%) | Memory: 37.30 MB (Top 81.82%)

class Solution:
    def minGroupsForValidAssignment(self, nums: List[int]) -> int:
        c = Counter(nums)

        if len(c) == 1:
            return 1

        def search(num):
            ans = 0
            for key in c:
                t = c[key] % num
                if t > c[key] // num:
                    return 0

                ans += ceil(c[key] / (num + 1))

            return ans

        minn, maxx = 1, min(c.values())
        ans = float('inf')
        for i in range(minn, maxx + 1):
            s = search(i)
            if s:
                ans = min(ans, s)

        return ans
