class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # sort by ascend order
        nums1.sort()

        # heapq in python is a minimal heap, so if we need to use a maximal heap, the element in the queue should be like: (-num, index)
        q = []
        for i, n in enumerate(nums2):
            heapq.heappush(q, (-n, i))

        n = len(nums1)
        l = 0
        r = n - 1
        ans = [0] * n

        while q:
            # pop out the maximum number from nums2
            num, i = heapq.heappop(q)
            num = -num

            # no number in nums1 > max number in nums2, so grap the minimum numer from nums1
            if nums1[r] <= num:
                ans[i] = nums1[l]
                l += 1
            else:
                ans[i] = nums1[r]
                r -= 1

        return ans