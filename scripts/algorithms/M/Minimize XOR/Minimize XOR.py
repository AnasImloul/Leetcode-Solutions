# Runtime: 0 ms (Top 100.00%) | Memory: 19.20 MB (Top 90.83%)

class Solution:
    def minimizeXor(self, num1: int, num2: int, mxbits = 31) -> int:

        num1 = bin(num1)[2:].rjust(mxbits,'0') 
        bitNum = num2.bit_count()
        ans = ['0'] * mxbits

        for i in range(mxbits):
            if num1[i] == '1':
                ans[i] = '1'
                bitNum-= 1
                if bitNum == 0: break

        else:
            for i in range(mxbits - 1, -1, -1):

                if num1[i] == '0':
                    ans[i] = '1'
                    bitNum-= 1
                    if bitNum == 0: break

        return int(''.join(ans),2)
