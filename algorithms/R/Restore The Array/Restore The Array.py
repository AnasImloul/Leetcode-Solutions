"""
                                "1317"
[1, 3, 1, 7]        -> [1] * nums(317, k)
[1, 3, 17]         
[1, 31, 7]
[1, 317]   
[13, 1, 7]          -> [13] * nums(17, k)
[13, 17]
[131, 7]
[1317]


                            "2020"    k = 30
[2000] x
[2, 020] x
[20, 20]

                            "67890" k = 90

[6, 7890] x
[6, 7, 8, 9, 0] x
[6, 7, 8, 90]   OK
[6, 78, 90]     OK
[67, 8, 90]     OK
[67, 89, 0] x
[678, 90] x
break because 678 > k (90), so neither 678, 6789 would be possible numbers

"""



class Solution:
    def num_arrays(self, s, k, memo):
        if not s:
            return 0
        memo_ans = memo.get(s)
        if memo_ans is not None:
            return memo_ans
        
        num = int(s)
        if num <= k:
            counter = 1
        else:
            counter = 0
    
        for i in range(len(s) - 1):
            # Stop when the number to the right side of the array is greater than k
            if int(s[:i + 1]) > k:
                break
            # Don't count leading zeros
            if s[i + 1] == "0":
                continue
            counter += self.num_arrays(s[i + 1:], k, memo)
        ans = counter % (10 ** 9 + 7)
        memo[s] = ans
        return ans
    
    def numberOfArrays(self, s: str, k: int) -> int:
        memo = {}
        return self.num_arrays(s, k, memo)
