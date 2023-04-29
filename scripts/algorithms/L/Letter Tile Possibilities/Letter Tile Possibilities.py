class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        n= len(tiles)
        tiles=list(tiles)
        s1=set()
        for i in range(1,n+1):
            s1.update(permutations(tiles,i))
        return len(s1)