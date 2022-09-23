# Runtime: 4205 ms (Top 48.47%) | Memory: 237.6 MB (Top 7.47%)
class Solution:
    def longestDupSubstring(self, s: str) -> str:
        """
        the length of substring will be between 0 and n
        we do a binary search between lengths and check if we can find +2 occurances of a duplicate
        we check using sliding window
        """

        def check_duplicate_count(window_len) -> str:

            visited = set()
            for i in range(0, len(s) - window_len):
                sub = s[i : i + window_len + 1]
                if sub in visited:
                    return sub
                visited.add(sub)

            return None

        l, r = 0, len(s) - 1
        ln = float("-inf")
        res = ""
        while l < r:
            candid_len = l + (r - l) // 2
            cand = check_duplicate_count(candid_len)
            if cand and len(cand) > ln:
                ln = len(cand)
                res = cand
            # try to make it larger if possible
            if cand:
                l = candid_len + 1
            else:
                r = candid_len

        return res