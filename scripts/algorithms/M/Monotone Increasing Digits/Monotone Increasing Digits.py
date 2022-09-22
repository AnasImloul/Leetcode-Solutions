# Runtime: 43 ms (Top 69.04%) | Memory: 13.9 MB (Top 20.57%)
class Solution:
    def monotoneIncreasingDigits(self, n: int) -> int:
        num = list(str(n))
        for i in range(len(num)-1):
            # Step1: When don't meet the condition, num[i]-=1 and repalce all num left into '9' and directly return
            # However, there is the case that num[i-1]==num[i], which will make num[i]-1<num[i-1]
            # So, traverse back to find the num that its num[i-1] != num[i](to make sure num[i-1]<=num[i]-1), then do step1 and return
            if num[i] > num[i+1]:
                while i >= 1 and num[i-1] == num[i]:
                    i -= 1
                num[i] = chr(ord(num[i])-1)
                return int(''.join(num[:i+1]+['9']*(len(num)-i-1)))
        return n