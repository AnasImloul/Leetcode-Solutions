# Runtime: 187 ms (Top 25.00%) | Memory: 44.60 MB (Top 39.00%)

class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        num = list(map(int, str(n)))

        @cache
        def dp(pos: int, tight: bool, chosen_digit: int) -> int:
            if pos == len(num): return 1
            res = 0
            bound = num[pos] if tight else 10
            for i in range(bound + 1):
                if i == 10: continue
                if chosen_digit & (1 << i): continue 
                new_tight = i == bound
                new_chosen_digit = 0 if chosen_digit == 0 and i == 0 \
                                     else chosen_digit | (1 << i)
                res += dp(pos + 1, new_tight, new_chosen_digit)
            return res

        return dp(0, True, 0) - 1
