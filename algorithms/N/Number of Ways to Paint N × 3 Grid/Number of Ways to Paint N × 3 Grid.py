class Solution:
    def numOfWays(self, n: int) -> int:
        two_c_options = 6
        tot_options = 12
        for i in range(n-1):
            temp = tot_options
            tot_options = (two_c_options * 5) + ((tot_options - two_c_options) * 4)
            two_c_options = (two_c_options * 3) + ((temp - two_c_options) * 2)
            tot_options = tot_options % (1000000007)
        return tot_options
