class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        gray_code = [x ^ (x >> 1) for x in range(2 ** n)]
        start_i = gray_code.index(start)
        return gray_code[start_i:] + gray_code[:start_i]