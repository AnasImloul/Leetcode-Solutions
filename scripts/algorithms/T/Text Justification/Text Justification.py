// Runtime: 46 ms (Top 59.19%) | Memory: 14 MB (Top 55.27%)
class Solution:
    def fullJustify(self, words: List[str], maxwidth: int) -> List[str]:
        curr = 0
        last = []
        res = []
        for i in words:
            if curr + len(i) + len(res) <= maxwidth:
                curr += len(i)
                res.append(i)
            else:
                last.append(res)
                curr = len(i)
                res = [i]
        last.append(res)
        ans = []
        for idx ,row in enumerate(last):
            x = maxwidth-len("".join(row))
            t = len(row)-1
            if t == 0:
                ans.append(row[0] + " "*(x))
            elif idx != len(last)-1:
                spaces = x//t
                rem = x%t
                res = row[0]
                for i in row[1:]:
                    temp = spaces
                    if rem:
                        temp += 1
                        rem -= 1
                    res = res + " "*temp + i
                    # print(res, temp)
                ans.append(res)
            else:
                res = row[0]
                for i in row[1:]:
                    res = res + ' '+i
                res = res + " "*(maxwidth-len(res))
                ans.append(res)

        return ans