# Runtime: 162 ms (Top 30.92%) | Memory: 14.2 MB (Top 58.94%)
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        nxt = ""
        ar, de = senate.count('R'), senate.count('D')
        r , d = 0, 0
        while(ar and de) :
            for i in senate :
                if (i== 'R' and d == 0):
                    r += 1
                    nxt = nxt + 'R'
                elif (i== 'R' and d > 0):
                    d -= 1
                elif (i== 'D' and r > 0):
                    r -= 1
                elif(i== 'D' and r == 0):
                    d += 1
                    nxt = nxt + 'D'
            senate = nxt
            nxt = ""
            ar, de = senate.count('R'), senate.count('D')
        if (ar) :
            return 'Radiant'
        else:
            return 'Dire'