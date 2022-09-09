# Runtime: 61 ms (Top 94.40%) | Memory: 13.8 MB (Top 59.53%)
class Solution(object):
   def isPalindrome(self,x):
       return str(x) == str(x)[::-1]