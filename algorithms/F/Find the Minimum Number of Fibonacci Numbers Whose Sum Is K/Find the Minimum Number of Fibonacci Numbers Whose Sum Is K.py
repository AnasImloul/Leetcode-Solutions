class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        fib_sq = [1, 1]
        while fib_sq[-1] + fib_sq[-2] <= k:
            fib_sq.append(fib_sq[-1]+fib_sq[-2])
        counter = 0
        for i in range(len(fib_sq)-1, -1, -1):
            if fib_sq[i] <= k:
                counter += 1
                k -= fib_sq[i]
        return counter
