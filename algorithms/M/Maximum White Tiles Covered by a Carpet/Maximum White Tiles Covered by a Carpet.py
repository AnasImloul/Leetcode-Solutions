class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        tiles.sort()
		#j: window index
        j = cover = res = 0
        for i in range(len(tiles)):
			#slide the window as far as we can to cover fully the intervals with the carpet
            while j<len(tiles) and tiles[j][1]-tiles[i][0] + 1 <= carpetLen:
                cover += tiles[j][1]-tiles[j][0] + 1
                j += 1
			#process the remnant, that is, when the tiles[j] is covered by the carpet partially(not fully)
            if j<len(tiles) and tiles[j][0]-tiles[i][0] + 1 <= carpetLen:
                res = max(res, cover + carpetLen-(tiles[j][0]-tiles[i][0]))
            else:
                res = max(res, cover)
            #when the tiles[j] is covered partially, the interval is not added to the variable cover
			if i!=j:
                cover -= tiles[i][1]-tiles[i][0]+1
			j = max(j, i+1)
        return res