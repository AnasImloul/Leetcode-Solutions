class Solution:
    def capitalizeTitle(self, title: str) -> str:
        return " ".join([word.capitalize() if len(word) > 2 else word.lower() for word in title.split()])
