# Runtime: 4011 ms (Top 18.39%) | Memory: 19.7 MB (Top 40.23%)
class Solution:
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        res = [] # Result set
        sums.sort()

        while len(sums) > 1:
            num = sums[-1] - sums[-2] # max - secondMax
            countMap = Counter(sums) # Get count of each elements
            excluding = [] # Subset sums that do NOT contain num
            including = [] # Subset sums that contain num

            for x in sums:
                if countMap.get(x) > 0:
                    excluding.append(x)
                    including.append(x+num)
                    countMap[x] -= 1
                    countMap[x+num] -= 1

            # Check validity of excluding set
            if 0 in excluding:
                sums = excluding
                res.append(num)
            else:
                sums = including
                res.append(-1*num)

        return res