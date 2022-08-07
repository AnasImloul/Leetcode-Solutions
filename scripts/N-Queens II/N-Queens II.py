class Solution:
    def totalNQueens(self, n: int) -> int:
        res=0
        #用于存放结果
        pdia=set()
        ndia=set()
        col=set()

        def backtrack(r):
            #利用r作为一种计数，表示目前所在的行数
            if r==n:
            #判断已经完成棋盘，返回结果
                nonlocal res
                res+=1
                return
            for c in range(n):
                #对于n行n列的棋盘，每次在每一行我们尝试n种选择，
                #即每个岔路口有n条路线
                if (r+c) in pdia or (r-c) in ndia or c in col:
                    #如果在同一对角线，或同一列，则不符合要求
                    continue
                col.add(c)
                pdia.add(r+c)
                ndia.add(r-c)
                
                backtrack(r+1)
                
                col.remove(c)
                pdia.remove(r+c)
                ndia.remove(r-c)

        backtrack(0)
        return res
