// Runtime: 188 ms (Top 86.16%) | Memory: 23.30 MB (Top 59.07%)

from typing import List
import heapq


class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        heap = [(row[0], i, 0) for i, row in enumerate(nums)]
        heapq.heapify(heap)
        ans = [-10**9, 10**9]
        right = max(row[0] for row in nums)
        while heap:
            left, row, col = heapq.heappop(heap)
            if right - left < ans[1] - ans[0]:
                ans = [left, right]
            if col + 1 == len(nums[row]):
                return ans
            right = max(right, nums[row][col + 1])
            heapq.heappush(heap, (nums[row][col + 1], row, col + 1))

# Tests:
if __name__ == '__main__':
    s = Solution()
    # test case 1
    output1 = s.smallestRange([[4,10,15,24,26],[0,9,12,20],[5,18,22,30]])
    expected_output1 = [20,24]
    assert output1 == expected_output1, f"Expected {expected_output1}, but got {output1}"
    # test case 2
    output2 = s.smallestRange([[1,2,3],[1,2,3],[1,2,3]])
    expected_output2 = [1,1]
    assert output2 == expected_output2, f"Expected {expected_output2}, but got {output2}"
    print("All tests passed!")
