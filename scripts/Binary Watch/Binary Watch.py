class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans=[]
        for h in range(12):
            d=0
            for i in range(5):
                if(h&(1<<i)):
                    d+=1
            for m in range(60):
                c=d
                for i in range(7):
                    if(m&(1<<i)):
                        c+=1
                if(c==turnedOn):
                    ans.append(f'{h}:{m:02d}')
        return ans
