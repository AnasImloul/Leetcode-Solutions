# Runtime: 330 ms (Top 23.27%) | Memory: 14.6 MB (Top 66.82%)

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:

        cols={}
        l=len(strs)
        l_s = len(strs[0])
        delete = set()
        for i in range(l):
            for col in range(l_s):
                if col in cols:
                    if cols[col]>strs[i][col]:
                        delete.add(col)
                cols[col] = strs[i][col]
        return len(delete)