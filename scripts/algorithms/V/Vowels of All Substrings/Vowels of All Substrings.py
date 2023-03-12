class Solution:
    def countVowels(self, word: str) -> int:
        count = vowelIndexSum = 0
        vowels = {'a', 'e', 'i', 'o', 'u'}

        for i, c in enumerate(word, start=1):
            if c in vowels:
                vowelIndexSum += i
            count += vowelIndexSum
        
        return count