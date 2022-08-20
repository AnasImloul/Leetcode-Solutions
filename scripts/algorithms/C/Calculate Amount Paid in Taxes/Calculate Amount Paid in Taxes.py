# Runtime: 75 ms (Top 95.72%) | Memory: 13.9 MB (Top 34.37%)

class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        taxtot=0
        if(brackets[0][0]<income):
            taxtot+=brackets[0][0]*(brackets[0][1])
            income-=brackets[0][0]
        else:
            taxtot+=income*(brackets[0][1])
            return taxtot/100
        i=1
        while(income>0 and i<len(brackets)):
            if(income>(brackets[i][0]-brackets[i-1][0])):
                taxtot+=(brackets[i][0]-brackets[i-1][0])*brackets[i][1]
                income-=brackets[i][0]-brackets[i-1][0]
            else:
                taxtot+=income*brackets[i][1]
                income=0
            i+=1
        return taxtot/100