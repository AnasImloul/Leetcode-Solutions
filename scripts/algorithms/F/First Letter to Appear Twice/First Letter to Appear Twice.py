class Solution:
    def repeatedCharacter(self, s: str) -> str:
        occurences = defaultdict(int)
        for char in s:
            occurences[char] += 1
            if occurences[char] == 2:
                return char
