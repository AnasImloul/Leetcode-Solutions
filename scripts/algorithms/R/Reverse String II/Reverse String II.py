# Runtime: 92 ms (Top 5.11%) | Memory: 14.1 MB (Top 58.38%)
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        a=list(s)
        for i in range(0,len(a),2*k):
            a[i:i+k]=a[i:i+k][::-1]
        print(a)
        return("".join(a))