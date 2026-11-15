# Runtime: 856 ms (Top 21.43%) | Memory: 61.90 MB (Top 92.86%)

class Solution:
    def query(self, tree: List[int], ind: int, left: int, right: int, x: int, y: int) -> int:
        if left >= x and right <= y:
            return tree[ind]
        mid = (left + right) >> 1
        r = -1
        if x <= mid:
            r = self.query(tree, ind << 1, left, mid, x, y)
        if y > mid:
            r = max(r, self.query(tree, (ind << 1) | 1, mid + 1, right, x, y))
        return r

    def update(self, tree: List[int], ind: int, left: int, right: int, x: int, y: int) -> None:
        tree[ind] = max(tree[ind], y)
        if left >= x and right <= x:
            return
        mid = (left + right) >> 1
        if x <= mid:
            self.update(tree, ind << 1, left, mid, x, y)
        else:
            self.update(tree, (ind << 1) | 1, mid + 1, right, x, y)

    def maximumSumQueries(self, nums1: List[int], nums2: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums1)
        all_nums = defaultdict(int)
        v = [(nums1[i], nums2[i]) for i in range(n)]
        for num in nums2:
            all_nums[num] += 1
        v.sort()
        m = len(queries)
        ind = [i for i in range(m)]
        for query in queries:
            all_nums[query[1]] += 1
        ind.sort(key=lambda x: queries[x][0], reverse=True)
        mv = 0
        for key in sorted(all_nums.keys()):
            mv += 1
            all_nums[key] = mv
        tree = [-1] * (mv << 2)
        r = [0] * m
        j = n - 1
        for i in ind:
            while j >= 0 and v[j][0] >= queries[i][0]:
                self.update(tree, 1, 1, mv, all_nums[v[j][1]], v[j][0] + v[j][1])
                j -= 1
            r[i] = self.query(tree, 1, 1, mv, all_nums[queries[i][1]], mv)
        return r
