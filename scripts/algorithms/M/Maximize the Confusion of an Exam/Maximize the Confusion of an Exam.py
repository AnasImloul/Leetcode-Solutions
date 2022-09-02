# Runtime: 482 ms (Top 77.29%) | Memory: 14.4 MB (Top 36.09%)
class Solution:
    def maxConsecutiveAnswers(self, string: str, k: int) -> int:
        result = 0
        j = 0
        count1 = k
        for i in range(len(string)):
            if count1 == 0 and string[i] == "F":
                while string[j] != "F":
                    j+=1
                count1+=1
                j+=1

            if string[i] == "F":
                if count1 > 0:
                    count1-=1

            if i - j + 1 > result:
                result = i - j + 1

        j = 0
        count2 = k
        for i in range(len(string)):
            if count2 == 0 and string[i] == "T":
                while string[j] != "T":
                    j+=1
                count2+=1
                j+=1

            if string[i] == "T":
                if count2 > 0:
                    count2-=1

            if i - j + 1 > result:
                result = i - j + 1

        return result