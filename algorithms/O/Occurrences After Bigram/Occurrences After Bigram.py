class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        l=text.split()
        result=[]
        size=len(l)
        cur, nxt=0, 1
        while(nxt<size):
            if l[cur]==first and l[nxt]==second:
                if nxt+1<size:
                    result.append(l[nxt+1])
                else:
                    break
            cur+=1
            nxt+=1
        return result
