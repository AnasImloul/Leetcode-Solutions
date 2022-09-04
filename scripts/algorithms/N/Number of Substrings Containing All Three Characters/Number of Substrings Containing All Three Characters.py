# Runtime: 466 ms (Top 30.17%) | Memory: 14.4 MB (Top 31.83%)
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        start = 0
        end = 0
        counter = 0
        store = {'a' : 0, 'b' : 0, 'c' : 0}

        for end in range(len(s)):
            store[s[end]] += 1

            while store['a'] > 0 and store['b'] > 0 and store['c'] > 0:
                counter += (len(s) - end)
                store[s[start]] -= 1
                start += 1

        return counter