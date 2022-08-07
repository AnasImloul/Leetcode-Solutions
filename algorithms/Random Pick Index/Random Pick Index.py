class Solution:
    def __init__(self, nums: List[int]):
        self.multimap = defaultdict(list)
        for i, n in enumerate(nums):
            self.multimap[n].append(i)

    # O(1) time complexity
    def pick(self, target: int) -> int:
        return random.choice(self.multimap[target])
