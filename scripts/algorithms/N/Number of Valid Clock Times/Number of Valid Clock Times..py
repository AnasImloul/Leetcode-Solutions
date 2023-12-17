// Runtime: 105 ms (Top 5.12%) | Memory: 16.30 MB (Top 19.12%)

import re


class Solution:
    """
    Time:   O(1)
    Memory: O(1)
    """

    def countTime(self, time: str) -> int:
        pattern = time.replace('?', '.')
        return sum(
            re.fullmatch(pattern, f'{hour:02}:{minute:02}') is not None
            for hour in range(24)
            for minute in range(60)
        )
