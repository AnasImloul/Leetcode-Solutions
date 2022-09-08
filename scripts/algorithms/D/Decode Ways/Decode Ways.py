# Runtime: 48 ms (Top 59.57%) | Memory: 14.1 MB (Top 30.54%)
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == '0' or '00' in s:
            return 0
        l = len(s)
        if l == 1:
            return 1
        elif l == 2:
            if s[1] == '0':
                if s[0] == '1' or s[0] == '2':
                    return 1
                else:
                    return 0
            else:
                if int(s) <= 26:
                    return 2
                else:
                    return 1
        dp = [1]
        if s[1] == '0':
            if s[0] == '1' or s[0] == '2':
                dp.append(1)
            else:
                return 0
        else:
            if int(s[:2]) <= 26:
                dp.append(2)
            else:
                dp.append(1)
        for i in range(2, l):
            num = 0
            if s[i] == '0':
                if s[i-1] != '1' and s[i-1] != '2':
                    return 0
                else:
                    num = dp[i-2]
            elif s[i-1] == '1' or (s[i-1] == '2' and int(f'{s[i-1]}{s[i]}') <= 26):
                num = dp[i-1]+dp[i-2]
            else:
                num = dp[i-1]
            dp.append(num)
        return dp[l-1]