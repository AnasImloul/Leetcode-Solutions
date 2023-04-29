class Solution:

    from collections import defaultdict

    def isPossible(self, nums):
        # If the length of the array is less than 3, it's not possible to create subsequences of length 3 or more.
        if len(nums) < 3:
            return False

        # 'count' dictionary stores the frequency of each number in the input array.
        count = defaultdict(int)

        # 'tails' dictionary stores the number of subsequences that end at a certain number.
        tails = defaultdict(int)

        # Populate the 'count' dictionary with the frequency of each number.
        for num in nums:
            count[num] += 1

        # Iterate through the input array.
        for num in nums:
            # If the count of the current number is 0, it means this number has already been used in a subsequence.
            if count[num] == 0:
                continue
            # If there is a subsequence that ends with the current number minus 1,
            # it means we can extend that subsequence by adding the current number.
            elif tails[num - 1] > 0:
                tails[num - 1] -= 1  # Decrease the count of the tails that end with the current number minus 1.
                tails[num] += 1  # Increase the count of the tails that end with the current number.
            # If there are enough numbers after the current number to form a subsequence,
            # create a new subsequence starting with the current number.
            elif count[num + 1] > 0 and count[num + 2] > 0:
                count[num + 1] -= 1  # Decrease the count of the next number.
                count[num + 2] -= 1  # Decrease the count of the number after the next number.
                tails[num + 2] += 1  # Increase the count of the tails that end with the number after the next number.
            else:
                # If we can't extend an existing subsequence or start a new one, return False.
                return False

            # Decrease the count of the current number since it's used in a subsequence.
            count[num] -= 1

        # If the function successfully iterates through the entire array, return True.
        return True
