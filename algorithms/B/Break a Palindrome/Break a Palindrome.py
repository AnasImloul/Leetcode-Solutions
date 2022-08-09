class Solution(object):
    def breakPalindrome(self, palindrome):
        """
        :type palindrome: str
        :rtype: str
        """
        s = palindrome
        palindrome = [ch for ch in s]
        if len(palindrome) == 1:
            return ""
        
        for i in range(len(palindrome)//2):
            if palindrome[i] != 'a':
                palindrome[i] = 'a'
                return "".join(palindrome)
        palindrome[-1] = 'b'
        return "".join(palindrome)
        
        
                
                
