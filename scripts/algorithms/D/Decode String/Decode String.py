# Runtime: 67 ms (Top 5.09%) | Memory: 13.9 MB (Top 20.12%)
class Solution:
    def decodeString(self, s: str) -> str:
        def helper(index, encodedStr):
            k = 0
            string = ""

            # len(s) will be diffrent depend of subString
            while index < len(encodedStr):
                if encodedStr[index] == "[": # we found opening bracket - call helper to find sub string
                    new_index , SubStr = helper(index+1, encodedStr)
                    # add SubStr to string
                    string += (k*SubStr)
                    k , index = 0 , new_index
                elif encodedStr[index].isdigit():
                    k = k*10 + int(encodedStr[index])
                elif encodedStr[index] == "]": # we found closing bracket - return sub string
                    return index, string
                else:
                    string += encodedStr[index] # add curr char to sting

                index +=1
            return index, string

        _ , decodedStr = helper(0,s)
        return decodedStr
