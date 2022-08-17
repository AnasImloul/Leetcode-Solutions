class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a1, b1 = num1[:-1].split("+")
        a2, b2 = num2[:-1].split("+")
        a1, b1, a2, b2 = int(a1), int(b1), int(a2), int(b2)
        real = a1*a2-b1*b2
        imaginary = a1*b2+a2*b1
        return str(real)+"+"+str(imaginary)+"i"
