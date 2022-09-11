# Runtime: 55 ms (Top 37.91%) | Memory: 13.8 MB (Top 61.66%)
class Solution:
    def numDifferentIntegers(self, word: str) -> int:

        word = re.findall('(\d+)', word)
        numbers = [int(i) for i in word]

        return len(set(numbers))