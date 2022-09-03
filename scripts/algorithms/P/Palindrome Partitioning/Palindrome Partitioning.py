# Runtime: 1302 ms (Top 13.95%) | Memory: 35.7 MB (Top 6.05%)
"""
we can approach this problem using manacher's algorithm with backtracking and recursion
"""
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        lookup = {"": [[]]}
        def lps(s):
            if s in lookup:
                return lookup[s]

            final_res = []
            result_set = set()
            for k in range(len(s)):
                i, j = k, k

                # check for odd length palindromes
                while i>= 0 and j < len(s) and s[i] == s[j]:
                    # palindrome found
                    res = []
                    for partition in lps(s[:i]):
                        res.append(partition + [s[i:j+1]])
                    for partition in res:
                        for part in lps(s[j+1:]):
                            temp = partition + part
                            if tuple(temp) not in result_set:
                                result_set.add(tuple(temp))
                                final_res.append(temp)
                    i-=1
                    j+=1

                # check for even length palindromes
                i, j = k, k+1
                while i >= 0 and j < len(s) and s[i] == s[j]:
                    # palindrome found
                    res = []
                    for partition in lps(s[:i]):
                        res.append(partition + [s[i:j+1]])
                    for partition in res:
                        for part in lps(s[j+1:]):
                            temp = partition + part
                            if tuple(temp) not in result_set:
                                result_set.add(tuple(temp))
                                final_res.append(temp)
                    i-=1
                    j+=1
            lookup[s] = final_res
            return final_res
        return lps(s)