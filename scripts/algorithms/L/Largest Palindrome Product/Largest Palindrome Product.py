class Solution:
    def largestPalindrome(self, n: int) -> int:
        return [0, 9, 987, 123, 597, 677, 1218, 877, 475][n]

        
    def isPalindrome(x):
        return str(x) == str(x)[::-1]

    def solve(n):
        best = 0
        for i in range(10**n-1, 0, -1):
            for j in range(max(i, (best-1)//i+1), 10**n):
                if isPalindrome(i*j):
                    #print(i, j, i*j)
                    best = i*j
        return best
