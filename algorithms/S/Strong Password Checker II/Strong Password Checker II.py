class Solution:
    def strongPasswordCheckerII(self, pwd: str) -> bool:
        return (
            len(pwd) > 7
            and max(len(list(p[1])) for p in groupby(pwd)) == 1
            and reduce(
                lambda a, b: a | (1 if b.isdigit() else 2 if b.islower() else 4 if b.isupper() else 8), pwd, 0
            ) == 15
        )
