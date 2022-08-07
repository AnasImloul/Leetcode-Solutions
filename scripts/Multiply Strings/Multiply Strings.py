class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def convertToInt(numStr):
            currNum = 0
            N = len(numStr)
            for i in range(N - 1, -1, -1):
                digit = ord(numStr[i]) - ord('0')
                currNum += pow(10, N-i-1) * digit
                
            return currNum
        
        n1 = convertToInt(num1)
        n2 = convertToInt(num2)
        return str(n1 * n2)
      
