# Runtime: 76 ms (Top 9.80%) | Memory: 14.1 MB (Top 5.65%)
INF = float("inf")

class Solution:
    def videoStitching(self, clips, time ) :
        clips.sort()

        @lru_cache
        def dp(ci, reeled):

            if ci > len(clips) - 1:
                return INF#

            if clips[ci][0] > reeled:
                return INF # cantt take this

            if clips[ci][1] >= time:
                return 1
            # takee
            a1 = 1 + dp(ci+1, clips[ci][1])

            # not take
            a2 = dp(ci+1, reeled)

            return min(a1, a2)

        res = dp(0, 0)
        if res == INF:
            return -1
        else:
            return res