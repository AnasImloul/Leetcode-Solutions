# Runtime: 87 ms (Top 77.87%) | Memory: 13.9 MB (Top 86.89%)
class Solution:
    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        prev_p, cur_p = [0] * (n+1), [0] * (n+1)

        for i in range(k+1, goal+1):
            if i == k+1:
                prev_p[i] = math.factorial(n) // math.factorial(n-i)
            else:
                for j in range(k+1, min(i, n)+1):
                    cur_p[j] = prev_p[j-1] * (n - j + 1) + prev_p[j] * (j-k)
                prev_p, cur_p = cur_p, [0] * (n+1)
        return prev_p[n] % (10**9 + 7)