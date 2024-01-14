// Runtime: 79 ms (Top 83.25%) | Memory: 17.60 MB (Top 13.89%)

class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        result = 1
        freq = {}
        # {remainder : {num : frequency}}
        for x in nums:
            if not x % k in freq:
                freq[x % k] = {}
            if not x in freq[x % k]:
                freq[x % k][x] = 0
            freq[x % k][x] += 1
        for fr in freq.values(): # loop for s1, s2, ...
            s = sorted([[k, v] for k, v in fr.items()])
            def f(i: int) -> int:
                if i == len(s):
                    return 1
                skip = f(i + 1) # 1 * f(i + 1)
                take = 2 ** s[i][1] - 1 # take s[i]
                if i + 1 < len(s) and s[i + 1][0] - s[i][0] == k: # next number is s[i] + k
                    take *= f(i + 2)
                else:
                    take *= f(i + 1)
                return skip + take
            result *= f(0) # f(s1) * f(s2) ...
        return result - 1 # -1 for empty subset
