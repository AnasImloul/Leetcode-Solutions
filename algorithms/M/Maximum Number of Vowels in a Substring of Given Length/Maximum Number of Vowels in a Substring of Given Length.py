class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        
        def find_count_vowels(string):
            lst_vowels= ['a', 'e', 'i', 'o', 'u']
            c=0
            for i in string:
                if i in lst_vowels:
                    c+=1
            return c
            
        
        lst_vowels= ['a', 'e', 'i', 'o', 'u']
        if k>len(s):
            return find_count_vowels(s)
        dp = [0]*(len(s)-k+1)
        dp[0] = find_count_vowels(s[:k])
        for i in range(1,len(s)-k+1):
            
           
            if s[i-1] in lst_vowels and s[i+k-1] in lst_vowels:
                dp[i] = dp[i-1]
            elif s[i-1] in lst_vowels and s[i+k-1] not in lst_vowels:
                dp[i] = dp[i-1] - 1

            elif s[i-1] not in lst_vowels and s[i+k-1] in lst_vowels:
                dp[i] = dp[i-1] + 1
            else:
                dp[i] = dp[i-1]
        return max(dp)
                
