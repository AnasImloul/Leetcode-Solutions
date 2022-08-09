class Solution:
    def maxProduct(self, s: str) -> int:
        # n <= 12, which means the search space is small
        n = len(s)
        arr = []
        
        for mask in range(1, 1<<n):
            subseq = ''
            for i in range(n):
                # convert the bitmask to the actual subsequence
                if mask & (1 << i) > 0:
                    subseq += s[i]
            if subseq == subseq[::-1]:
                arr.append((mask, len(subseq)))
        
        result = 1
        for (mask1, len1), (mask2, len2) in product(arr, arr):
            # disjoint
            if mask1 & mask2 == 0:
                result = max(result, len1 * len2)
        return result
