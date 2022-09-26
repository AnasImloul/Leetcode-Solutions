# Runtime: 133 ms (Top 41.78%) | Memory: 13.9 MB (Top 70.89%)
class SegmentTree:
    def __init__(self, xs):
        #cnts[v] means that the node's interval is active
        self.cnts = defaultdict(int)
        #total[v] length of active intervals that are contained the node's interval
        self.total = defaultdict(int)
        self.xs = xs

    def update(self, v, tl, tr, l, r, h):
        #node interval [tl,tr] does not overlap with query interval [l,r]
        if r < tl or tr < l: return
        #node interval is included in the query interval
        if l <= tl and tr <= r:
            self.cnts[v] += h
        else:
            tm = (tl + tr)//2
            self.update(v*2, tl, tm, l, r, h)
            self.update(v*2+1, tm+1, tr, l, r, h)
        #node interval is included in the active interval
        if self.cnts[v] > 0:
            self.total[v] = self.xs[tr + 1] - self.xs[tl]
        else:
            self.total[v] = self.total[v*2] + self.total[v*2+1]
        return self.total[v]

class Solution:
    def rectangleArea(self, rectangles):
        #index i means the interval from xs[i] to xs[i+1]
        xs = sorted(set([x for x1, y1, x2, y2 in rectangles for x in [x1, x2]]))
        xs_i = {x:i for i, x in enumerate(xs)}
        st = SegmentTree(xs)
        L = []
        for x1, y1, x2, y2 in rectangles:
            L.append([y1, 1, x1, x2])
            L.append([y2, -1, x1, x2])
        L.sort()
        cur_y = cur_x_sum = area = 0
        for y, open_close, x1, x2 in L:
            area += (y - cur_y) * cur_x_sum
            cur_y = y
            #one index corresponds to one interval, that's why we use xs_i[x2]-1 instead of xs_i[x2]
            st.update(1, 0, len(xs) - 1, xs_i[x1], xs_i[x2]-1, open_close)
            cur_x_sum = st.total[1]

        return area % (10 ** 9 + 7)