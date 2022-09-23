# Runtime: 1961 ms (Top 83.96%) | Memory: 47.2 MB (Top 5.66%)
MAX_N = 2*10**4
MAX_BIT = MAX_N.bit_length()
class MajorityChecker:

    def __init__(self, nums: List[int]):
        n = len(nums)
        self.bit_sum = [[0] * MAX_BIT for _ in range(n+1)]
        for i in range(1, n+1):
            for b in range(MAX_BIT):
                self.bit_sum[i][b] = self.bit_sum[i-1][b] + ((nums[i-1] >> b) & 1)
        self.num_idx = defaultdict(list)
        for i in range(n):
            self.num_idx[nums[i]].append(i)

    def query(self, left: int, right: int, threshold: int) -> int:
        num = 0
        for b in range(MAX_BIT):
            if self.bit_sum[right+1][b] - self.bit_sum[left][b] >= threshold:
                num |= 1 << b
        l = bisect.bisect_left(self.num_idx[num], left)
        r = bisect.bisect_right(self.num_idx[num], right)
        if r-l >= threshold:
            return num
        return -1