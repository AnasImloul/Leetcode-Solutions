# Runtime: 33 ms (Top 88.95%) | Memory: 13.8 MB (Top 62.28%)
class Solution:
    def toHex(self, num: int) -> str:
        ret = ["0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"]
        ans = ""

        if num < 0:
            num = pow(2,32) +num

        if num == 0:
            return "0"
        while num > 0:
            ans = ret[num%16] +ans
            num = num//16

        return ans