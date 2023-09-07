# Runtime: 79 ms (Top 60.3%) | Memory: 16.74 MB (Top 25.6%)

class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        vowels = 'aeiouAEIOU'
        count = 0
        for i in range(left, right+1):
            if words[i][0] in vowels and words[i][-1] in vowels:
                count += 1
        return count
