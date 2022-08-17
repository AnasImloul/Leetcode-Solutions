from bisect import bisect_left as bl, bisect_right as br
class RangeModule:

    def __init__(self):
        self._X = []

    def addRange(self, left: int, right: int) -> None:
        # Main Logic 
        #   If idx(left) or idx(right) is odd, it's in a interval. So don't add it. 
        #   If idx(left) or idx(right) is even, it's not in any interval. So add it as new interval 
        #   Slice array[idx(left) : idx(right)]
        #       1) both odd: Nothing is added. Merge all middle intervals. 
        #       2) both even: Add new intervals. Merge all middle intervals
        #       3) idx(left) is even: update start point of next interval with left
        #       4) idx(right) is even: update end point of previous interval with right
        # Bisect_left vs. Bisect_right
        #   left need to proceed all interval closing at left, so use Bisect_left
        #   right need to go after all interval openning at right, so use Bisect_right
        i, j = bl(self._X, left), br(self._X, right)
        self._X[i : j] = [left] * (i % 2 == 0) + [right] * (j % 2 == 0)
        

    def queryRange(self, left: int, right: int) -> bool:
        # Main logic 
        #   If idx of left/right is odd, it's in a interval. Else it's not. 
        #   If idx of left&right is the same, they're in the same interval
        # Bisect_left vs. Bisect_right
        #   [start, end). Start is included. End is not. 
        #   so use bisect_right for left 
        #   so use bisect_left for right 
        i, j = br(self._X, left), bl(self._X, right)
        return i == j and i % 2 == 1
        

    def removeRange(self, left: int, right: int) -> None:
        # Main Logic 
        #   If idx(left) is odd, the interval that contains left need to change end point to left 
        #   If idx(right) is odd, the interval that contains right need to change start point to right
        #   Else, everything from idx(left) to idx(right) is removed. Nothing is changed. 
        # Bisect_left vs. Bisect_right
        #   Same as addRange
        i, j = bl(self._X, left), br(self._X, right)
        self._X[i : j] = [left] * (i % 2 == 1) + [right] * (j % 2 == 1)

