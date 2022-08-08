class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x=Counter(moves)
        flag=False
        if(x['U']==x['D'] and x['L']==x['R']):
            flag=True
        return flag
