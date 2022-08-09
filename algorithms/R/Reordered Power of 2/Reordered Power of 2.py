class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        counter = Counter(str(n))
        power = 0
        counter_for_2 = Counter(str(2**power))
        while counter_for_2.total() <= counter.total():
            if counter_for_2 == counter:
                return True
            power += 1
            counter_for_2 = Counter(list(str(2**power)))
        return False
