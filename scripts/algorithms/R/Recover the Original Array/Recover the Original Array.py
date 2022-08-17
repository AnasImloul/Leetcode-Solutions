class Solution(object):
    def recoverArray(self, nums):
        nums.sort()
        mid = len(nums) // 2
        # All possible k are (nums[j] - nums[0]) // 2, otherwise there is no num that satisfies nums[0] + k = num - k.
        # For nums is sorted, so that any 2 elements (x, y) in nums[1:j] cannot satisfy x + k = y - k.
        # In other words, for any x in nums[1:j], it needs to find y from nums[j + 1:] to satisfy x + k = y - k, but
        # unfortunately if j > mid, then len(nums[j + 1:]) < mid <= len(nums[1:j]), nums[j + 1:] are not enough.
        # The conclusion is j <= mid.
		# If you think it’s not easy to understand why mid is enough, len(nums) can also work well
		# for j in range(1, len(nums)):  
        for j in range(1, mid + 1):  # O(N)
            if nums[j] - nums[0] > 0 and (nums[j] - nums[0]) % 2 == 0:  # Note the problem described k is positive.
                k, counter, ans = (nums[j] - nums[0]) // 2, collections.Counter(nums), []
                # For each number in lower, we try to find the corresponding number from higher list.
                # Because nums is sorted, current n is always the current lowest num which can only come from lower
                # list, so we search the corresponding number of n which equals to n + 2 * k in the left
                # if it can not be found, change another k and continue to try.
                for n in nums:  # check if n + 2 * k available as corresponding number in higher list of n
                    if counter[n] == 0:  # removed by previous num as its corresponding number in higher list
                        continue
                    if counter[n + 2 * k] == 0:  # not found corresponding number in higher list
                        break
                    ans.append(n + k)
                    counter[n] -= 1  # remove n
                    counter[n + 2 * k] -= 1  # remove the corresponding number in higher list
                if len(ans) == mid:
                    return ans
