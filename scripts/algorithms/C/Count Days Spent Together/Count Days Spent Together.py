# Runtime: 0 ms (Top 100.00%) | Memory: 19.30 MB (Top 18.66%)

class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str,
                                arriveBob: str,   leaveBob: str) -> int:

        d = {1:0,   2:31,  3:59,   4:90,   5:120,  6:151,         # <-- 1)
             7:181, 8:212, 9:243, 10:273, 11:304, 12:334}         #

        def days(date):                                           #
            mon, day = date.split('-')                            # <--2)
            return d[int(mon)]+int(day)                           #

        arrive, leave = (max(days(arriveAlice),days(arriveBob)),  # <-- 3)
                         min(days(leaveAlice ),days(leaveBob )))  #

        return  max(leave-arrive+1,0)                             # <-- 4)
