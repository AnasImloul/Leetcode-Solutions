# Runtime: 47 ms (Top 36.0%) | Memory: 16.40 MB (Top 44.2%)

class Solution:
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        d={}
        for i,v in enumerate(pattern):
            if v in d:
                d[v].append(i)
            else:
                d|={v:[i]}
        #DICTIONARY CONTAINING LETTERS AND THEIR INDICES
        ans=[]
        for i in words:
            e={}
            for j,v in enumerate(i):
                if v in e:
                    e[v].append(j)
                else:
                    e|={v:[j]}
        #DICTIONARY CONTAINING LETTERS OF INDICES OF CURRENT WORD
            for u,v in zip(d.values(),e.values()):
                #COMPARING EACH VALUE
                if u!=v:
                    break
            #IF SUCCESSFUL APPEND TO ANS
            else:ans.append(i)
        return ans