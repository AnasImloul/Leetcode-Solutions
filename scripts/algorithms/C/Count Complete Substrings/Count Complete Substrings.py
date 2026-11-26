# Runtime: 5731 ms (Top 9.26%) | Memory: 25.60 MB (Top 14.81%)

class Solution:
    def countCompleteSubstrings(self, w: str, k: int) -> int:
        def calc(s):
            res = 0
            v = len(s)
            for i in range(1, 27):
                if i * k > v: break
                l = i * k
                cnt = Counter(s[:l])
                freq = Counter(cnt.values())

                if freq[k] == i: res += 1

                for idx in range(v - l):
                    freq[cnt[s[idx]]] -= 1
                    cnt[s[idx]] -= 1
                    freq[cnt[s[idx]]] += 1

                    freq[cnt[s[idx+l]]] -= 1
                    cnt[s[idx+l]] += 1
                    freq[cnt[s[idx+l]]] += 1

                    if freq[k] == i: res += 1
            return res

        idx = 0
        ans = 0
        n = len(w)
        for i in range(1, n):
            if abs(ord(w[i]) - ord(w[i-1])) > 2:
                ans += calc(w[idx:i])
                idx = i
        ans += calc(w[idx:])
        return ans
