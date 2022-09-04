# Runtime: 62 ms (Top 10.11%) | Memory: 13.8 MB (Top 56.37%)
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        return (ord(coordinates[0])+ord(coordinates[1]))%2