# Runtime: 22 ms (Top 46.14%) | Memory: 48.70 MB (Top 39.89%)

class Solution:
    def vowelStrings(self, words: List[str], 
                           queries: List[List[int]]) -> List[int]:

        vowels = lambda w: w[0] in 'aeiou' and w[-1] in 'aeiou' #
        words = map(vowels, words)                              # <-- 1)

        pref = list(accumulate(words, initial = 0))             # <-- 2) 

        return [pref[r+1] - pref[l] for l,r in queries]         # <-- 3)
