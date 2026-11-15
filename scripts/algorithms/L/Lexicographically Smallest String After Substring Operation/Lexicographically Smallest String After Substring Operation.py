# Runtime: 60 ms (Top 98.31%) | Memory: 26.50 MB (Top 8.47%)

class Solution:
    def smallestString(self, s: str) -> str:

        arr = s.split('a')

        for i, ss in enumerate(arr):
            if ss:
                arr[i] = ''.join([chr(ord(ch)-1) for ch in ss])
                break

        else: return s[:-1] + 'z'

        return 'a'.join(arr)
