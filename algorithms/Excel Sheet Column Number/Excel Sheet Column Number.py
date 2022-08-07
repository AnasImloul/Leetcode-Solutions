def let_to_num(char):
    abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    return abc.index(char) + 1

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        ans = 0
        for i in range(len(columnTitle)):
            ans *= 26
            ans += let_to_num(columnTitle[i])
        return ans
