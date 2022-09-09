# Runtime: 67 ms (Top 7.61%) | Memory: 13.9 MB (Top 27.96%)
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        dic1={2:"Sunday", 3:"Monday", 4:"Tuesday", 5:"Wednesday", 6:"Thursday", 0:"Friday", 1:"Saturday"}
        dic2={1:31,2:28,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
        y=year-1971
        lp=0
        for i in range(1971,year):
            if i%4==0:
                lp+=1
        dy=y*365+lp
        dm=0
        for i in range(1,month):
            if i==2 and year%4==0 and year!=2100:
                dm+=1
            dm+=dic2[i]
        dd=day
        td=dd+dm+dy
        print(td)
        return dic1[(td-1)%7]