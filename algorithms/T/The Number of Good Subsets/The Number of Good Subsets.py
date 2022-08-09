from collections import Counter
from functools import lru_cache
from typing import List, Tuple

PRIMES = (2, 3, 5, 7, 11, 13, 17, 19, 23, 29)

BIG_NUMBER = 10 ** 9 + 7


@lru_cache(maxsize=32)
def factor(n) -> Tuple[int, bool]:
    """
    :param n: 1 < n <= max(PRIMES)
    :return: (factors in bit mask, has duplicate primes)
    """
    output = 0

    for e in PRIMES:
        while n > 1 and n % e == 0:
            mask = 1 << e

            if mask & output:
                return -1, False

            output |= mask

            n //= e

        if n == 1:
            break

    return output, True


class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        masks = []

        for e in nums:
            if 1 < e and (fr := factor(e))[1]:
                masks.append(fr[0])

        cnt = Counter(masks)
        good_nums = Counter({0: 0})

        for mask in cnt:
            for f in tuple(good_nums):
                if f & mask:  # some prime dividing "mask" is also dividing the "f"
                    continue

                new_mask = f | mask

                count_for_new_mask = good_nums[new_mask] + cnt[mask] * (good_nums[f] or 1)

                good_nums[new_mask] = count_for_new_mask % BIG_NUMBER

        effect_of_one = pow(2, nums.count(1), BIG_NUMBER)
        total_subsets_without_one = sum(good_nums.values()) % BIG_NUMBER

        return (effect_of_one * total_subsets_without_one) % BIG_NUMBER
