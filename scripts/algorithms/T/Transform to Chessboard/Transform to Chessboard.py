class Solution(object):
    def movesToChessboard(self, board):
        N = len(board)
        ans = 0
        # For each count of lines from {rows, columns}...
        for count in (collections.Counter(map(tuple, board)),  # get row
                      collections.Counter(zip(*board))): #get column

            # If there are more than 2 kinds of lines,
            # or if the number of kinds is not appropriate ...
            if len(count) != 2 or sorted(count.values()) != [N/2, (N+1)/2]:
                return -1

            # If the lines are not opposite each other, impossible
            line1, line2 = count
            if not all(x ^ y for x, y in zip(line1, line2)):
                return -1

            # starts = what could be the starting value of line1
            # If N is odd, then we have to start with the more
            # frequent element
            starts = [int(line1.count(1) * 2 > N)] if N%2 else [0, 1]

            # To transform line1 into the ideal line [i%2 for i ...],
            # we take the number of differences and divide by two
            ans += min(sum((x-i) % 2 for i, x in enumerate(line1, start))
                       for start in starts) / 2            

        return ans
