class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        idx = {}
        acclens = [0]
        prevd = 1
        j = 0
        for i, c in enumerate(S + '1'):
            if c.isalpha():
                idx[acclens[-1] * prevd + j] = i
                j += 1
            else:
                acclens.append(acclens[-1] * prevd + j)
                prevd = int(c)
                j = 0
        k = K - 1
        for al in reversed(acclens[1:]):
            k %= al
            if k in idx:
                return S[idx[k]]
        return None  # should never reach this
