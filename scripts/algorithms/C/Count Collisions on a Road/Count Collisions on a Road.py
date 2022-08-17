class Solution:
    def countCollisions(self, directions: str) -> int:
        return sum(d!='S' for d in directions.lstrip('L').rstrip('R'))
