class Solution:
    def findLUSlength(self, s: List[str]) -> int:
        def lcs(X, Y):
            m = len(X)
            n = len(Y)
            L = [[None]*(n + 1) for i in range(m + 1)]
            for i in range(m + 1):
                for j in range(n + 1):
                    if i == 0 or j == 0 :
                        L[i][j] = 0
                    elif X[i-1] == Y[j-1]:
                        L[i][j] = L[i-1][j-1]+1
                    else:
                        L[i][j] = max(L[i-1][j], L[i][j-1])
            return L[m][n]
            
        k = 0 
        mp = {}
        for i in s:
            if len(i) not in mp:
                mp[len(i)] = [i]
            else:
                mp[len(i)].append(i)
            k = max(k , len(i))
        
        t = k
        while(k):
            if k not in mp:
              k -= 1
            else:
                curr = mp[k]
                n = len(curr)
                for i in range(n):
                    f = 0
                    for j in range(n):
                        if(i != j and curr[i] == curr[j]):
                            f = 1
                            break
                    if(not(f)):
                        ff = 0 
                        for j in range(k+1 , t+1):
                            if(ff):break
                            if(j not in mp): continue
                            for jj in mp[j]:
                                if(lcs(curr[i] , jj) == len(curr[i])):
                                    ff = 1
                                    break
                        if(not(ff)):return len(curr[i])
                k-=1
                
        return -1

        

        