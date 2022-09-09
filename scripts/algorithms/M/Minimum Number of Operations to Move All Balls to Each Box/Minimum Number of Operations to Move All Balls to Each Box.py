# Runtime: 68 ms (Top 97.39%) | Memory: 14.2 MB (Top 53.70%)
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        ans = [0]*len(boxes)
        leftCount, leftCost, rightCount, rightCost, n = 0, 0, 0, 0, len(boxes)
        for i in range(1, n):
            if boxes[i-1] == '1': leftCount += 1
            leftCost += leftCount # each step move to right, the cost increases by # of 1s on the left
            ans[i] = leftCost
        for i in range(n-2, -1, -1):
            if boxes[i+1] == '1': rightCount += 1
            rightCost += rightCount
            ans[i] += rightCost
        return ans