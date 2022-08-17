class Solution:
    def numWays(self, s: str) -> int:
        ones = 0

        # Count number of Ones
        for char in s:
            if char == "1":
                ones += 1

        # Can't be grouped equally if the ones are not divisible by 3
        if ones > 0 and ones % 3 != 0:
            return 0

        # Ways of selecting two dividers from n - 1 dividers 
        if ones == 0:
            n = len(s)
			# n = {3: 1, 4: 3, 5: 6, 6: 10, 7: 15 ... }
            return (((n - 1) * (n - 2)) // 2) % ((10 ** 9) + 7)

        # Number of ones in each group
        ones_interval = ones // 3

        # Number of zeroes which lie on the borders
        left, right = 0, 0

        # Iterator
        i = 0
        temp = 0

        # Finding the zeroes on the left and right border
        while i < len(s):
            temp += int(s[i]) & 1
            if temp == ones_interval:
                if s[i] == '0':
                    left += 1
            if temp == 2 * ones_interval:
                if s[i] == '0':
                    right += 1
            i += 1
        
        # The result is the product of number of (left + 1) and (right + 1)
        # Because let's assume it as we only want to fill up the middle group
        # The solution would be if we have zero then there might be a zero in the middle
        # Or there might not be the zero, so this might case is added and then
		# the events are independent so product of both the events
        return ((left + 1) * (right + 1)) % ((10 ** 9) + 7)

