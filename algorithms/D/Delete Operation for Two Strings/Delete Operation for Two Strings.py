class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        len1,len2=len(word1),len(word2)
        if not word1:
            return len2
        if not word2:
            return len1   
        table=[[ 0 for _ in range(len2)] for _ in range(len1)]
        
        if word1[0]==word2[0]:
            for i in range(len(word1)):
                table[i][0] = i
            for j in range(len(word2)):
                table[0][j] = j
        else:
            table[0][0]=2
            flag=True
            for i in range(1,len(word1)):
                if flag:
                    if word1[i]==word2[0]:
                        table[i][0]=table[i-1][0]-1
                        flag=False
                    else:
                        table[i][0]=table[i-1][0]+1
                else:
                    table[i][0]=table[i-1][0]+1
            flag=True
            for j in range(1,len(word2)):
                if flag:
                    if word1[0]==word2[j]:
                        table[0][j]=table[0][j-1]-1
                        flag=False
                    else:
                        table[0][j]=table[0][j-1]+1
                else:
                    table[0][j]=table[0][j-1]+1
                                      
        for i in range(1,len(word1)):
            for j in range(1,len(word2)):
                if word1[i]!=word2[j]:
                    table[i][j]=min(table[i-1][j],table[i][j-1])+1
                else:
                    table[i][j]=table[i-1][j-1]
        return table[-1][-1]
