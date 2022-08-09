class Solution:
    def bagOfTokensScore(self, tokens, power):
        tokens.sort()
        n = len(tokens)
        i, j = 0, n
        while i < j:
            if tokens[i] <= power:
                power -= tokens[i]
                i += 1
            elif i - (n - j) and j > i + 1:
                j -= 1
                power += tokens[j]
            else: break
        return i - (n - j)
