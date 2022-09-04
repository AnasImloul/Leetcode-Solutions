# Runtime: 2545 ms (Top 38.89%) | Memory: 37.8 MB (Top 95.24%)
class Solution:
    def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
        # prefix sum to save time
        acc = [0] + [*accumulate(packages)]
        packages.sort()

        ans = float('inf')
        for box in boxes:
            tmp = 0
            # deal with smallest box first
            box.sort()

            # record number of packages already dealt with
            start = 0

            for b in box:
                loc = bisect.bisect(packages, b)
                if loc == 0: continue
                tmp += b * (loc - start) - (acc[loc] - acc[start])

                # all are packaged
                if loc == len(packages):
                    ans = min(ans, tmp)
                    break

                start = loc

        return ans % (10 **9+7) if ans != float('inf') else -1