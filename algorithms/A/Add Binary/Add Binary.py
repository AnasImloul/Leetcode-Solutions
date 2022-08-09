class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """

        return str(bin(int(a, base = 2)+int(b, base = 2)))[2:]
