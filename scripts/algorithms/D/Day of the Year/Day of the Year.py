// Runtime: 123 ms (Top 44.98%) | Memory: 14 MB (Top 32.35%)
class Solution:
    def dayOfYear(self, date: str) -> int:
        d={1:31,2:28,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
        year=int(date[:4])
        if year%4==0:
            if year%100==0:
                if year%400==0:
                    d[2]=29
            else:
                d[2]=29
        month=int(date[5:7])
        day=int(date[8:])
        ans=0
        for i in range(1,month+1):
            ans+=d[i]
        return ans-(d[month]-day)