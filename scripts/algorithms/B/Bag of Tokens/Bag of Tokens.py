// Runtime: 51 ms (Top 88.07%) | Memory: 17.40 MB (Top 31.65%)

class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        i,j=0,len(tokens)-1
        m=score=0
        while i<j:
            if tokens[i]>power and score==0:
                break  
            if tokens[i]<=power:
                score+=1
                power-=tokens[i]
                m=max(m,score)
                i+=1
            else:
                if score>0:
                    score-=1
                    power+=tokens[j]
                    j-=1
        if i<len(tokens) and tokens[i]<=power:
            score+=1
            m=max(m,score)
        return m
