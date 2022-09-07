# Runtime: 11887 ms (Top 6.00%) | Memory: 14.2 MB (Top 88.00%)
class Solution:
    def numberOfCombinations(self, num: str) -> int:
        if num[0]=='0': return 0
        N=len(num)
        MOD=int(10**9+7)
        ways = (N+1)*[0]
        acc = list(ways)
        for n in range(1,N+1):
            ways[n] = int(n==N or num[n]!='0')
            for i in range(n+1,N+1):
                if i<N and num[i]=='0':
                    ways[i] = 0
                    continue
                ways[i] = (acc[i-n] + ((w := ways[i-n]) and i>=2*n and num[i-2*n:i-n] <= num[i-n:i] and w)) %MOD
            for i in range(n,N+1):
                a = (acc[i] + ways[i]) %MOD
                acc[i] = a
        return acc[N]