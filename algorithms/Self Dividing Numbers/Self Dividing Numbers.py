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
