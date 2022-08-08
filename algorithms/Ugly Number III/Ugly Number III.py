class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        times = [1,1,1]
        smallest = inf
        while n != 0:
            smallest = min ( times[0]*a,times[1]*b,times[2]*c)
            if times[0]*a == smallest: times[0] += 1
            if times[1]*b == smallest: times[1] += 1
            if times[2]*c == smallest: times[2] += 1
            n -= 1
        return smallest
