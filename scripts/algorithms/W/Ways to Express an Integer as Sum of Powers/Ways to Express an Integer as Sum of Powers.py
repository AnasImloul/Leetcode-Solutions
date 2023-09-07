# Runtime: 2371 ms (Top 59.7%) | Memory: 646.15 MB (Top 20.7%)

class Solution:
    MOD = 1_000_000_007

    def numberOfWays(self, num: int, power: int) -> int:
        @cache
        def calc_ways(i: int, left: int) -> int:
            if left == 0:
                return 1
            elif left < 0 or i >= len(candidates) or candidates[i] > left:
                return 0
            else:
                return (
                    calc_ways(i + 1, left) + calc_ways(i + 1, left - candidates[i])
                ) % self.MOD

        candidates = list(self.__get_candidates(num, power))
        return calc_ways(0, num)

    @staticmethod
    def __get_candidates(n: int, p: int) -> Generator:
        for num in map(lambda x: x ** p, range(1, n + 1)):
            if num <= n:
                yield num
            else:
                break