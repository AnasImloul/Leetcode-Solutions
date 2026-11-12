# Runtime: 85 ms (Top 70.43%) | Memory: 47.80 MB (Top 14.78%)

class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
		# example:  nums = [3,7,8,1,1,5], space = 2
        groups = defaultdict(list)
        for num in nums:
            groups[num % space].append(num)

        # print(groups) # defaultdict(<class 'list'>, {1: [3, 7, 1, 1, 5], 0: [8]}) groups is [3, 7, 1, 1, 5] and [8] 
        """ min of [3, 7, 1, 1, 5] can destroy all others (greedy approach) => 1 can destory 1,3,5,7 ... """
        performance = defaultdict(list)
        for group in groups.values():
            performance[len(group)].append(min(group))

        # print(performance) # defaultdict(<class 'list'>, {5: [1], 1: [8]})
		# nums that can destory 5 targets are [1], nums that can destory 1 target are [8] 
        return min(performance[max(performance)])
