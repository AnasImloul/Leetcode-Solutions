// Runtime: 59 ms (Top 23.94%) | Memory: 14 MB (Top 15.28%)
class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        counter_s = Counter(s)
        return min(counter_s[c] // count for c,count in Counter(target).items())