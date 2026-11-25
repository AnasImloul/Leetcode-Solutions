# Runtime: 1455 ms (Top 95.00%) | Memory: 32.90 MB (Top 82.50%)

class Solution:
    def maximumStrongPairXor(self, A: List[int]) -> int:
        res = 0
        for i in range(20, -1, -1):
            # 0011 -> 00110 Shift left
            res <<= 1
            pref, pref2 = {}, {}
            for a in A:
                p = a >> i
                if p not in pref:
                    pref[p] = pref2[p] = a
                pref[p] = min(pref[p], a)
                pref2[p] = max(pref2[p], a)
            for x in pref:
                # greedy guess
                y = res ^ 1 ^ x
                if x >= y and y in pref and pref[x] <= pref2[y] * 2:
                    # 00110 -> 00111 Add one to last bit
                    res |= 1
                    break
        return res
