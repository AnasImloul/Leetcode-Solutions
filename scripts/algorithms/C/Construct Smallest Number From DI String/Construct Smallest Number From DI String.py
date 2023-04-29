class Solution:
    def smallestNumber(self, pattern: str) -> str:
        arr, i = [1], 0
        while i < len(pattern):
            if pattern[i] == 'I':
                arr.append(len(arr) + 1)
                i += 1
                continue
            j = i + 1
            while j < len(pattern) and pattern[j] == 'D':
                j += 1
            end, start = arr[-1] + (j - i), arr[-1]
            del arr[-1]
            arr.extend(n for n in range(end, start - 1, -1))
            i = j
        return ''.join(map(str, arr))