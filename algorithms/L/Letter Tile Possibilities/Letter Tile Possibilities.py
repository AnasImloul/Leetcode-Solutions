class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        def dfs(potentialTile, tiles):
            if potentialTile not in result:
                if len(potentialTile) > 0:
                    result.add(potentialTile)
                for i in range(len(tiles)):
                    dfs(potentialTile+tiles[i], tiles[:i]+tiles[i+1:])
        result = set()
        dfs('',tiles)
        return len(result)
