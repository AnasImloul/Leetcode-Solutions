# Runtime: 173 ms (Top 90.14%) | Memory: 14.9 MB (Top 69.01%)
class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        q_cnt_1 = s1 = 0
        for i in range(n//2): # get digit sum and question mark count for the first half of `num`
            if num[i] == '?':
                q_cnt_1 += 1
            else:
                s1 += int(num[i])
        q_cnt_2 = s2 = 0
        for i in range(n//2, n): # get digit sum and question mark count for the second half of `num`
            if num[i] == '?':
                q_cnt_2 += 1
            else:
                s2 += int(num[i])
        s_diff = s1 - s2 # calculate sum difference and question mark difference
        q_diff = q_cnt_2 - q_cnt_1
        return not (q_diff % 2 == 0 and q_diff // 2 * 9 == s_diff) # When Bob can't win, Alice wins