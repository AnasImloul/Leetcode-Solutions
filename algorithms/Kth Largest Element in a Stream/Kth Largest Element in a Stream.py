class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.hp = []
        for x in nums:
            self.add(x)

        return None

    def add(self, val: int) -> int:
        heapq.heappush(self.hp, (val))
        if len(self.hp) > self.k:
            heapq.heappop(self.hp)

        return self.get_kth_largest()

    def get_kth_largest(self):
        return self.hp[0]
