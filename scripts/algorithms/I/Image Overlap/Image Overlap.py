# Runtime: 593 ms (Top 76.00%) | Memory: 14.7 MB (Top 44.00%)
class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        list1, list2 = [], []
        res = 0
        for r in range(n):
            for c in range(n):
                if img1[r][c]:
                    list1.append((r, c))
                if img2[r][c]:
                    list2.append((r, c))

        shiftDict = defaultdict(int)
        for x1, y1 in list1:
            for x2, y2 in list2:
                dx, dy = x2 - x1, y2 - y1
                shiftDict[(dx, dy)] += 1

        return max(shiftDict.values()) if shiftDict else 0