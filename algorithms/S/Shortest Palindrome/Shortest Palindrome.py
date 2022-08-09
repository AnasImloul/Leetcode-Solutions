class Solution:
    def shortestPalindrome(self, s: str) -> str:
        
        end = 0
        
        # if the string itself is a palindrome return it
        if(s == s[::-1]):
            return s
        
        # Otherwise find the end index of the longest palindrome that starts
        # from the first character of the string
        
        for i in range(len(s)+1):
            if(s[:i]==s[:i][::-1]):
                end=i-1
        
        # return the string with the remaining characters other than
        # the palindrome reversed and added at the beginning
        
        return (s[end+1:][::-1])+s
