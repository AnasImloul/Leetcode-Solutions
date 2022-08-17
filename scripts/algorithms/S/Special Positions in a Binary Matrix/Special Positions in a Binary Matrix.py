class Solution(object):
    def numSpecial(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        r=len(mat)
        c=len(mat[0])
        
        r_c={}
        l_c={}
        
        for i in range(r):
            flag=0
            for j in range(c):
                if(mat[i][j]==1):
                    flag+=1
            r_c[i]=flag
        for i in range(c):
            flag=0
            for j in range(r):
                if(mat[j][i]==1):
                    flag+=1
            l_c[i]=flag
        ret=0
        for i in range(r):
            for j in range(c):
                if(mat[i][j]==1 and l_c[j]==1 and r_c[i]==1):
                    ret+=1
        return ret
