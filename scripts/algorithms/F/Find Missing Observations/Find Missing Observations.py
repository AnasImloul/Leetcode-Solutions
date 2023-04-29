class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        missing_val, rem = divmod(mean * (len(rolls) + n) - sum(rolls), n)
        if rem == 0:
            if 1 <= missing_val <= 6:
                return [missing_val] * n
        elif 1 <= missing_val < 6:
            return [missing_val + 1] * rem + [missing_val] * (n - rem)
        return []