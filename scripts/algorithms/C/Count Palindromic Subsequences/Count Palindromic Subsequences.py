class Solution:
    def countPalindromes(self, s: str) -> int:
        if len(s) < 5: return 0
        n = len(s)
        s = [int(c) for c in s]
        left, right = [0] * n, [0] * n
        cur1, cur2 = [0] * 10, [0] * 100
        cur1[s[0]] += 1
        for i in range(1, n - 1):
            for j in range(10): cur2[j * 10 + s[i]] += cur1[j]
            left[i] = cur2[:]
            cur1[s[i]] += 1
        cur1, cur2 = [0] * 10, [0] * 100
        cur1[s[-1]] += 1
        for i in range(n - 2, 1, -1):
            for j in range(10): cur2[j * 10 + s[i]] += cur1[j]
            right[i] = cur2[:]
            cur1[s[i]] += 1
        ans, MOD = 0, 10 ** 9 + 7
        for i in range(2, n - 2):
            ans = (ans + sum(left[i - 1][j] * right[i + 1][j] for j in range(100))) % MOD
        return ans