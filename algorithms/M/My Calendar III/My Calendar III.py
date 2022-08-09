import bisect
class MyCalendarThree:

    def __init__(self):
        self.events = []        

    def book(self, start: int, end: int) -> int:
        L, R = 1, 0
        bisect.insort(self.events, (start, L))
        bisect.insort(self.events, (end, R))
        res = 0
        cnt = 0
        for _, state in self.events:
            #if an interval starts, increase the counter
            #othewise, decreas the counter
            cnt += 1 if state == L else -1
            res = max(res, cnt)
        return res