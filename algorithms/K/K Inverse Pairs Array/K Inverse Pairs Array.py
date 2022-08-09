class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        # Complexity:
        # - Time: O(N*K)
        # - Space: O(K)

        # Special cases that can be short-circuited right away
        # - For k=0, there's only one solution, which is having the numbers in sorted order
        #     DP(n, 0) = 1
        if k == 0:
            return 1
        # - There can't be more than n*(n-1)/2 inverse pairs, which corresponds to the numbers in reverse order
        #     DP(n, k) = 0 for all k > n*(n-1)/2
        if k > n * (n - 1) // 2:
            return 0

        # For the general case, we notice that:
        #     DP(n+1, k) = sum(DP(n, i) for i in [max(0, k-n), k])
        # i.e., adding an additional number (the biggest one n+1):
        # - We can have it at the end, in which case it doesn't create any reverse pairs,
        #   and so the number of configurations with k reverse pairs is DP(n,k)
        # - Or we can have it one before the end, in which case it creates exactly reverse pairs,
        #   and so the number of configurations with k reverse pairs is DP(n,k-1)
        # - And so on and so forth, such that having it `i` places before the end create exactly `i` reverse pairs,
        #   and so the number of configurations with k reverse pairs is DP(n,k-i)
        # This relationship allows us to compute things iteratively with a rolling window sum
        kLine = [0] * (k + 1)
        kLine[0] = 1
        previousKLine = kLine.copy()
        maxFeasibleK = 0
        for m in range(2, n + 1):
            previousKLine, kLine = kLine, previousKLine
            rollingWindowSum = 1
            maxFeasibleK += m - 1
            endKLineIdx = min(k, maxFeasibleK) + 1
            intermediateKLineIdx = min(endKLineIdx, m)
            for kLineIdx in range(1, intermediateKLineIdx):
                rollingWindowSum = (rollingWindowSum + previousKLine[kLineIdx]) % _MODULO
                kLine[kLineIdx] = rollingWindowSum
            for kLineIdx in range(intermediateKLineIdx, endKLineIdx):
                rollingWindowSum = (rollingWindowSum + previousKLine[kLineIdx] - previousKLine[kLineIdx - m]) % _MODULO
                kLine[kLineIdx] = rollingWindowSum
        return kLine[k]


_MODULO = 10 ** 9 + 7
