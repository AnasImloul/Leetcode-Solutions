# Runtime: 99 ms (Top 32.60%) | Memory: 13.9 MB (Top 25.64%)
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []
        for num in range(left, right + 1):
            num_str = str(num)
            if '0' in num_str:
                continue
            elif all([num % int(digit_str) == 0 for digit_str in num_str]):
                res.append(num)
        return res