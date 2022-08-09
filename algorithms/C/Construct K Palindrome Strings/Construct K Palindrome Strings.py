class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        characters, numOfOdds = {}, 0
        for char in s:
            if char not in characters:
                characters[char] = 0
            characters[char] += 1
        for key in characters:
            if characters[key]%2 != 0:
                numOfOdds += 1
        return numOfOdds <= k and k <= len(s)
