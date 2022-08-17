class CountIntervals:

    def __init__(self):
	# initialize the merged intervals list as below to handle edge cases
        self.interv = [(-inf, -inf), (inf, inf)]
        self.cov = 0   

    def add(self, left: int, right: int) -> None:
        
        interv = self.interv
        
		# find the left most position for inserting of the new potentially merged interval
		# we use `left - 1` because the interval coverage is inclusive
        li = bisect.bisect_left(interv, left - 1, key=itemgetter(1))
        lval = min(interv[li][0], left)
		
		# find the right most position for inserting the new potentially merged interval
		# we use `right + 1` because the interval coverage is inclusive
        ri = bisect.bisect_right(interv, right + 1, key=itemgetter(0))
        rval = max(interv[ri - 1][1], right)

		# find the coverage of the intervals that will be replaced by the new interval
        to_delete = 0
        for _ in range(li, ri):
            to_delete += interv[_][1] - interv[_][0] + 1
            
		# udpate the coverage
        self.cov += rval - lval + 1 - to_delete
        interv[li: ri] = [(lval, rval)]

    def count(self) -> int:
        return self.cov
