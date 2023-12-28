// Runtime: 3460 ms (Top 87.5%) | Memory: 38.10 MB (Top 67.5%)

from sortedcontainers import SortedList

class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        sl = SortedList()
        length = SortedList()
        curr = 0
        for char, it in itertools.groupby(s):
            c = sum(1 for _ in it)
            length.add(c)
            sl.add((curr, curr + c, char))
            curr += c
        ans = []
        for char, i in zip(queryCharacters, queryIndices):
            t = (i, math.inf, 'a')
            index = sl.bisect_right(t) - 1
            to_remove = [sl[index]]
            to_add = []
            left, right, original_char = to_remove[0]
            if original_char != char:
                length.remove(right - left)
                if right - left > 1:
                    if i == left:
                        left += 1
                        to_add.append((left, right, original_char))
                        length.add(right - left)
                    elif i == right - 1:
                        right -= 1
                        to_add.append((left, right, original_char))
                        length.add(right - left)
                    else:
                        to_add.append((left, i, original_char))
                        length.add(i - left)
                        to_add.append((i + 1, right, original_char))
                        length.add(right - (i + 1))
                
                l, r = i, i + 1
                if index - 1 >= 0 and sl[index - 1][1:3] == (i, char):
                    l, old_r, _ = sl[index - 1]
                    to_remove.append(sl[index - 1])
                    length.remove(old_r - l)
                if index + 1 < len(sl) and sl[index + 1][0] == i + 1 and sl[index + 1][2] == char:
                    old_l, r, old_length = sl[index + 1]
                    to_remove.append(sl[index + 1])
                    length.remove(r - old_l)
                length.add(r - l)
                sl.add((l, r, char))
                for t in to_remove:
                    sl.remove(t)
                sl.update(to_add)
            # print(sl)
            # print(length)
            ans.append(length[-1])

        return ans
