class Solution:
    def group(self, word):
        result = [[word[0], 1]]
        for i in range(1, len(word)):
            if word[i] == result[-1][0]:
                result[-1][1] += 1
            else:
                result.append([word[i], 1])
        return result

    def expressiveWords(self, s: str, words: list[str]) -> int:
        final = self.group(s)
        count = 0
        for i in words:
            temp = self.group(i)
            flag = True
            if len(final) != len(temp):
                continue
            else:
                ptr = 0
                while ptr < len(final):
                    if temp[ptr][0] != final[ptr][0] or (final[ptr][1] < 3 and final[ptr][1] != temp[ptr][1]) or final[ptr][1] < temp[ptr][1]:
                        flag = False
                        break
                    ptr += 1
                if flag:
                    count += 1
        return count
