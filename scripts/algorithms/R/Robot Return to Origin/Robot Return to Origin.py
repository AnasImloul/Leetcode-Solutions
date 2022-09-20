# Runtime: 88 ms (Top 52.68%) | Memory: 14.1 MB (Top 38.28%)
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x=Counter(moves)
        flag=False
        if(x['U']==x['D'] and x['L']==x['R']):
            flag=True
        return flag