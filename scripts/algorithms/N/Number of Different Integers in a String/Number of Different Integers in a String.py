// Runtime: 34 ms (Top 85.83%) | Memory: 16.50 MB (Top 46.61%)

class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        word = re.findall('(\d+)', word)
        nums = [int(i) for i in word]
        
        return len(set(nums))
