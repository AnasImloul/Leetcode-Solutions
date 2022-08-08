class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        s = [0]
        n = len(arr)
        if n <= 1:
            return 0 
        for i in range(n):
            s.append(s[-1]^arr[i])
        # a = s[i] ^ s[j], b = s[j] ^ s[k+1]  
        count = defaultdict(int)
        # a = b <-> a ^ b == 0 <-> (s[i] ^ s[j]) ^ (s[j] ^ s[k+1]) == 0 
        # <-> s[i] ^ (s[j] ^ m ) = 0 (where m = s[j] ^ s[k+1])
        # <-> s[i] ^ s[k+1] == 0 <-> s[i] == s[k+1]
      
        res = 0 
        # len(s) == n+1, 0<=i<=n-2, 1<=k<=n-1, i+1<=j<=k
        for i in range(n-1):
            for k in range(i+1, n):
                if s[i] == s[k+1]:
                    res += (k-i)
        return res 
