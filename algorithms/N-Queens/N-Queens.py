class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        coord = self.findNextRows(0, n)
        ans = []
        for c in coord:
            temp = []
            for j in c:
                temp.append("."*j+"Q"+"."*(n-j-1))
            ans.append(temp)
        return ans
                        
    def findNextRows(self, i, n, h_occ=set(), d_occ=set(), ad_occ=set()):
		'''
		h_occ: occupied horizontal coordinate
		d_occ: occupied diagonal
		ad_occ: occupied anti-diagonal
		'''
        ans = []
        if i==n:
            return [[]]
        for j in range(n):
             if (j not in h_occ) and (j-i not in d_occ) and ((j-n+1)+i not in ad_occ):
                    h_occ.add(j)
                    d_occ.add(j-i)
                    ad_occ.add((j-n+1)+i)
                    temp = self.findNextRows(i+1, n, h_occ, d_occ, ad_occ)
                    h_occ.remove(j)
                    d_occ.remove(j-i)
                    ad_occ.remove((j-n+1)+i)
                    ans += [[j]+l for l in temp]
        return ans
                
                
