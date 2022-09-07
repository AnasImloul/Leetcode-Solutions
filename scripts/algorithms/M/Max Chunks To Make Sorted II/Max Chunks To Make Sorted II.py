# Runtime: 187 ms (Top 16.67%) | Memory: 14.5 MB (Top 12.03%)
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        sortedArr = sorted(arr)

        posMap = defaultdict(list)
        for i in range(len(sortedArr)):
            posMap[sortedArr[i]].append(i) # keep track the right sortedArr[i] position

        idx = len(arr) - 1
        cnt = 0
        for i in range(len(arr) - 1, -1, -1):
            idx = min(idx, posMap[arr[i]][-1]) # the smallest position need to move arr[i] to correct position
            posMap[arr[i]].pop()
            if i == idx:
                cnt += 1
                idx -= 1
        return cnt