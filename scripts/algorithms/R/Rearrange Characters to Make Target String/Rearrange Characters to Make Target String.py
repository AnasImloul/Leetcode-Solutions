# Runtime: 55 ms (Top 32.02%) | Memory: 13.9 MB (Top 67.72%)
class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        counter_s = Counter(s)
        return min(counter_s[c] // count for c,count in Counter(target).items())