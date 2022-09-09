# Runtime: 65 ms (Top 7.05%) | Memory: 13.8 MB (Top 68.36%)
class Solution:
    def countDigitOne(self, n: int) -> int:
        num = str(n)[::-1]
        count = 0
        for i in range(len(num)-1, -1, -1):
            pv = 10**i # placevalue
            # mulitplicity of current digit (how many times it will be repeated)
            mul = n//(pv*10)
            rem = n % pv # remainder of current place value
            count += mul * pv # count for number of times 1 occurs in this place when the current digit is considered to be less than 1
            # if the current digit is greater than 1 then additional number of 1's are added to the count (equivalent to the place value)
            if num[i] > '1':
                count += pv
            # if the current digit is equal to 1 then additional number of 1's are added to the count (equivalent to the number modded by the current place value)
            if num[i] == '1':
                count += rem + 1
        return count
