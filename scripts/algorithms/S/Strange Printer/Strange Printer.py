# Runtime: 878 ms (Top 47.91%) | Memory: 16.1 MB (Top 47.44%)
class Solution(object):
    def strangePrinter(self, s):
        """
        :type s: str
        :rtype: int
        """
        # remove duplicate letters from s.
        tmp = []
        for c in s:
            if len(tmp) == 0 or tmp[-1] != c:
                tmp.append(c)
        s = "".join(tmp)

        _m = {}
        def _dp(i, j, background):
            if j < i:
                return 0
            elif i == j:
                return 1 if background != s[i] else 0
            elif (i, j, background) in _m:
                return _m[(i, j, background)]

            ans = len(s)

            # shrink s[i:j+1] to s[i_:j_+1] according to the background letter
            i_ = i + 1 if s[i] == background else i
            j_ = j - 1 if s[j] == background else j

            if s[i_] == s[j_]:
                # case "AxxxA" => best strategy is printing A first
                ans = _dp(i_ + 1, j_ - 1, s[i_]) + 1
            else:
                # otherwise, print first letter, try every possible print length
                for p in range(i_, j_ + 1):
                    # searching is needed only if s[p] == s[i_]
                    # e.g. s="ABCDEA"print 'A' on s[0:1] is equivalent to s[0:5]
                    if s[p] != s[i_]:
                        continue
                    l = _dp(i_, p, s[i_])
                    r = _dp(p + 1, j_, background)
                    ans = min(ans, l + r + 1)
            _m[(i, j, background)] = ans
            return ans

        return _dp(0, len(s) - 1, '')