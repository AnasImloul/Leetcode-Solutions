class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        patterns = [6, 31, 156, 781, 3906, 19531, 97656, 488281, 2441406, 12207031, 61035156, 305175781, 1525878906]
        for i in patterns[::-1]:
            k = k % i
            if k == i - 1:
                return 0
        return 5
