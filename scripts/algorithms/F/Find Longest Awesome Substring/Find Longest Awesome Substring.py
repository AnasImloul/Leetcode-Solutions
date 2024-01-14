// Runtime: 658 ms (Top 96.88%) | Memory: 18.30 MB (Top 28.13%)

class Solution:
    def longestAwesome(self, s: str) -> int:
        # li = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512]
        li = [2**i for i in range(10)]
        # checker = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512}
        checker = set(li)
        checker.add(0)
        # di: k = prefix xor, v = the first idx I got a new prefix_xor_value.
        di = collections.OrderedDict({0: -1})
        maxLength = prefix_xor = 0
        
        for i in range(len(s)):
            prefix_xor ^= li[int(s[i])]
            # Found a new prefix_xor_value
            if prefix_xor not in di:
                di[prefix_xor] = i
            
            # XOR operation with previous prefix_xor_value
            for key in di.keys():
                if i - di[key] <= maxLength:
                    break
				# s[di[key] : i] is Awesome Substring
                if key ^ prefix_xor in checker:
                    maxLength = i - di[key]
        return maxLength
            
