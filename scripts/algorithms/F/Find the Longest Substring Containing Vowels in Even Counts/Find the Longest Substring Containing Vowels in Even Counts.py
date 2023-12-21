// Runtime: 636 ms (Top 16.95%) | Memory: 64.80 MB (Top 5.08%)

class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        integrals = [(False, False, False, False, False)] # integrals[10][mapping["a"]] == False means we have seen "a" appears even times before index 10
        mapping = {
            "a": 0,
            "i": 1,
            "u": 2,
            "e": 3,
            "o": 4
        }

        for v in s:
            vector = list(integrals[-1])
            if v in mapping: # if v is a vowel
                vector[mapping[v]] = not vector[mapping[v]] # toggle that dimension, because if v had appeared even times before, it becomes odd times now
            integrals.append(tuple(vector))

        seen = {}
        res = 0

        for i, v in enumerate(integrals):
            if v in seen: # we have seen this vector before
                res = max(res, i - seen[v]) # compare its substring length
            else:
                seen[v] = i # just record the first time each vector appears

        return res
