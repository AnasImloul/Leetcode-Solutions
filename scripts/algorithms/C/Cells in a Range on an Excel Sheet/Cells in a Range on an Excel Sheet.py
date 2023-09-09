# Runtime: 52 ms (Top 33.3%) | Memory: 16.43 MB (Top 7.2%)

class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        start, end = s.split(':')
        start_letter, start_num = start[0], int(start[-1])
        end_letter, end_num = end[0], int(end[1])
        alphabet = list('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
        alphabet_slice = \
            alphabet[alphabet.index(start_letter):alphabet.index(end_letter) + 1]
        res = list()
        for el in alphabet_slice:
            res += [el + str(num) for num in range(start_num, end_num + 1)]
        return res