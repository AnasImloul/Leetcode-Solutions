class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        i, s, hash_map = 1, '0', {'1': '0', '0': '1'}
        for i in range(1, n):
            s = s + '1' + ''.join((hash_map[i] for i in s))[::-1]
        return s[k-1]