class Solution:

    def __init__(self):
        self.perSq = []

    def numSquares(self, n):
        # finding perfect squares up to n
        i = 1
        while i*i <= n:
            self.perSq.append(i*i)
            i += 1

        return self.lengths(n)

    # algorithm to find sum from perfect squares
    def outcomes(self, n, current):
        rem = n
        nums = []
        while sum(nums) != n:
            if current < len(self.perSq)*-1:
                current = self.perSq[0]

            val = self.perSq[current]

            if rem < val:
                current -= 1
                continue
            else:
                nums.append(val)
                rem -= val
                if (rem > 0) and (rem % val == 0):
                    nums.append(val)
                    rem -= val

        return len(nums)

    # algorithm to find sum with least possible numbers
    def lengths(self, n):
        data = []
        for i in range(-1, -1*(len(self.perSq)+1), -1):
            data.append(self.outcomes(n, i))

        return min(data)
