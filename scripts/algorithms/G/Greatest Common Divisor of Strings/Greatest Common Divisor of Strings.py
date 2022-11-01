# Runtime: 85 ms (Top 15.89%) | Memory: 14 MB (Top 5.19%)
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:

        if len(str2) > len(str1):
            str1, str2 = str2, str1

        curr_str2 = str2
        while True:

            rep = len(str1)//len(curr_str2)

            if curr_str2*rep == str1:
                return curr_str2

            found = False
            for i in range(len(curr_str2)-1, 1, -1):
                try_str2 = curr_str2[:i]
                rep2 = len(str2)//len(try_str2)

                if try_str2*rep2 == str2:
                    curr_str2 = try_str2
                    found = True
                    break

            if not found:
                break
        return ""