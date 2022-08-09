class Solution:
    def gridIllumination(self, n: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        rows = collections.Counter()
        cols = collections.Counter()
        diags1 = collections.Counter()
        diags2 = collections.Counter()
        lamps = {tuple(lamp) for lamp in lamps}
        
        for i, j in lamps:
            rows[i] += 1
            cols[j] += 1
            diags1[i + j] += 1
            diags2[i - j] += 1
        
        ans = []
        directions = ((-1, -1), (-1, 0), (-1, 1),
                      (0, -1), (0, 0), (0, 1),
                      (1, -1), (1, 0), (1, 1))
        
        for i, j in queries:
            if rows[i] or cols[j] or diags1[i + j] or diags2[i - j]:
                ans.append(1)
            else:
                ans.append(0)
            
            for di, dj in directions:
                newI, newJ = i + di, j + dj
                if (newI, newJ) not in lamps:
                    continue
                lamps.remove((newI, newJ))
                rows[newI] -= 1
                cols[newJ] -= 1
                diags1[newI + newJ] -= 1
                diags2[newI - newJ] -= 1
        
        return ans