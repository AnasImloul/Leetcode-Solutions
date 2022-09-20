# Runtime: 61 ms (Top 84.84%) | Memory: 14 MB (Top 37.55%)
class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:

        # use memoization
        def inf():
            return float('inf')
        mins = collections.defaultdict(inf)

        depth = 0

        # use top-down approach to recursively place squares
        # hL = height of horizontal leg of the "L" shape
        # vL = width of vertical leg of any "L" shape
        def minSquares(ii: int, jj: int, hL:int, vL:int):

            nonlocal depth
            # trim problems that are too deep
            if ((n, m, n, m) in mins) and (depth > mins[(n, m, n, m)]):
                return float('inf')

            depth += 1

            # trim empty legs
            if hL == 0:
                jj = vL
                hL = ii
            if vL == 0:
                ii = hL
                vL = jj
            # tranpose if necessary to trim duplicate sub-problems
            if ii > jj:
                ii, jj, hL, vL = jj, ii, vL, hL

            # print(f'{" "*(depth)}minSquares({ii}, {jj}, {hL}, {vL}) :: executing.')

            # don't recaculate overlapping subproblems
            if (ii, jj, hL, vL) not in mins:
                # print(f'{" "*(depth+1)}calculating a new value.')

                # ============
                # calculate new subproblem min based on shape
                # ============
                # deal with squares
                if (ii == jj == hL == vL):
                    # store 1 to return later
                    mins[(ii, jj, hL, vL)] = 1
                    # print(f'{" "*(depth+2)}Found a square = {mins[(n, m, hL, vL)]}')
                # deal with rectangles
                elif (ii == hL) and (jj == vL):
                    # cut a series of consecutively smaller squares
                    # from corner and recursively find
                    # the minSquares of each new L-shape
                    # print(f'{" "*(depth+2)}Found a rectangle.')
                    for length in range (ii, min(ii//2, jj//2), -1):
                        h = hL - length
                        v = vL - length
                        mins[(ii, jj, hL, vL)] = min(
                            mins[(ii, jj, hL, vL)],
                            minSquares(ii, jj, h, v) + 1
                        )
                    # print(f'{" "*(depth+2)}Final rectangle mins({ii}, {jj}, {hL}, {vL}) = {mins[(ii, jj, hL, vL)]}')
                # deal with "L"-shapes
                else:
                    # print(f'{" "*(depth+1)}Found an L-shape.')

                    # figure out which side to cut from
                    i = ii
                    j = jj
                    h = hL
                    v = vL
                    if hL < ii <= vL:
                        # cut from right
                        # print(f'{" "*(depth+2)}Cutting from right.')
                        v -= ii
                        j -= ii
                        pass
                    elif vL < jj <= hL:
                        # cut from top
                        # print(f'{" "*(depth+2)}Cutting from top.')
                        i -= jj
                        h -= jj
                        pass
                    elif hL <= vL < ii:
                        # cut from bottom
                        # print(f'{" "*(depth+2)}Cutting from bottom.')
                        i -= vL
                        if h >= i:
                            h = i
                            v = j
                        pass
                    elif vL <= hL < jj:
                        # cut from left
                        # print(f'{" "*(depth+2)}Cutting from left.')
                        j -= hL
                        if v >= j:
                            h = i
                            v = j
                        pass
                    else:
                        print(f'{" "*(depth+2)}could not figure out side to cut from | mins({ii}, {jj}, {hL}, {vL})')
                        pass

                    mins[(ii, jj, hL, vL)] = min(
                        mins[(ii, jj, hL, vL)],
                        minSquares(i, j, h, v) + 1
                    )

                    # print(f'{" "*(depth+1)}Final L-shape mins({ii}, {jj}, {hL}, {vL}) = {mins[(n, m, hL, vL)]}')
                    pass

            depth -= 1

            # return current min
            return mins[(ii, jj, hL, vL)]

        result = minSquares(n, m, n, m)
        # print(f'mins = {mins}')
        # print(f'result = {result}')

        return result