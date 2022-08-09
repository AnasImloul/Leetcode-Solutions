# OJ: https://leetcode.com/problems/stone-game-viii/
# Author: github.com/lzl124631x
class Solution:
    def stoneGameVIII(self, A: List[int]) -> int:
        return reduce(lambda memo, cur : max(memo, cur - memo), list(accumulate(A))[::-1][:-1])
