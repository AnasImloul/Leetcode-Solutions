class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        def kSmallestPairs(nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
            h = [(nums1[0]+nums2[0],0,0)]
            visited = set()
            res = []
            while h and k > 0:
                e, i, j = heappop(h)
                if (i,j) in visited: continue
                res.append(e)
                visited.add((i,j))
                if j+1 < len(nums2):
                    heappush(h,(nums1[i]+nums2[j+1],i,j+1))
                if i+1 < len(nums1):
                    heappush(h,(nums1[i+1]+nums2[j],i+1,j))
                k -= 1
            return res
        res = mat[0]
        for i in range(1, len(mat)):
            res = kSmallestPairs(res, mat[i], k)
        return res[-1]