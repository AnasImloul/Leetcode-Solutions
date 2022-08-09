class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        g = ''
        count = m = 0
        for x in word:
            if g and x < g[-1]:
                count = 0
                g = ''
            if not g or x > g[-1]:
                g += x
            count += 1
            if g == 'aeiou':
                m = max(m, count)
        return m
