// Runtime: 1039 ms (Top 5.41%) | Memory: 80.00 MB (Top 22.7%)

class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = sorted(nums1)
        self.nums2 = nums2
        self.hash2 = defaultdict(int)
        for n in nums2:
            self.hash2[n] += 1

    def add(self, index: int, val: int) -> None:
        self.hash2[self.nums2[index]] -= 1
        self.nums2[index] += val
        self.hash2[self.nums2[index]] += 1

    def count(self, tot: int) -> int:
        result = 0
        for n in self.nums1:
            if n >= tot:
                break
            result += self.hash2[tot - n]
        return result
