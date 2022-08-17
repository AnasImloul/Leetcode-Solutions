class Solution:
    def longestPalindrome(self, s: str) -> int:
        letters = {} 
        for letter in s: #count each letter and update letters dict
            if letter in letters:
                letters[letter] += 1
            else:
                letters[letter] = 1
        
        
        plus1 = 0 # if there is a letter with count of odd ans must +=1 
        ans = 0
        for n in letters.values():
            if n == 1: #1 can only appear in the middle of our word
                plus1 = 1
            elif n%2 == 0:
                ans += n
            else:
                ans += n - 1
                plus1 = 1
                
        return ans + plus1


