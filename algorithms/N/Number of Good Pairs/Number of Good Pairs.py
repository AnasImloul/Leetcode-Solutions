from itertools import combinations
class Solution:
    def numIdenticalPairs(self, nums) -> int:
        res = 0
		nums_set = set(nums)
        nums_coppy = nums
        for number in nums_set:
            number_found = []
            deleted = 0
            while True:
                try:
                    found = nums_coppy.index(number)
                    nums_coppy.remove(number)
                    if deleted > 0:
                        number_found.append(found + deleted)
                    else:
                        number_found.append(found + deleted)
                    deleted += 1
                except:
                    comb = list(combinations(number_found, 2))
                    res += len(comb)
                    break
        return res
