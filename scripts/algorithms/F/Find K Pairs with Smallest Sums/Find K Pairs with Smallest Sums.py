# Runtime: 1647 ms (Top 67.28%) | Memory: 34.4 MB (Top 27.52%)
import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:

        ans = []

        heapq.heapify(ans)

        for i in range(min(k,len(nums1))):
            for j in range(min(k,len(nums2))):
                pairs = [nums1[i],nums2[j]]
                if len(ans)<k:
                    heapq.heappush(ans,[-(nums1[i]+nums2[j]),pairs])
                else:
                    if nums1[i]+nums2[j]>-ans[0][0]:
                        break
                    heapq.heappush(ans,[-(nums1[i]+nums2[j]),pairs])
                    heapq.heappop(ans)

        res = []
        for i in range(len(ans)):
            res.append(ans[i][1])

        return res