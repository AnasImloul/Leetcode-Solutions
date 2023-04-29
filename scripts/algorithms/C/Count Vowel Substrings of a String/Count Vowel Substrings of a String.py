class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        vowels = {'a','e','i','o','u'}
        pointer = 0
        res = 0
        if len(word) <= 4:
            return 0
        while pointer != len(word)-4:
            # if set(list(word[pointer:pointer+5])) == vowels:
            #     temp = 1
            #     res += 1
            #     while set(list(word[pointer:pointer+temp+5])) == vowels and pointer+temp+4 != len(word):
            #         res += 1
            #         temp += 1
            # elif word[pointer] in vowels:
            #     temp = 1
            #     while set(list(word[pointer:pointer+5+temp])) != vowels:
            #         temp += 1
            #     res += 1
            # pointer += 1
            temp = 0
            if word[pointer] in vowels:
                while temp+pointer != len(word)-4:
                    test_1 = set(list(word[pointer:pointer+temp+5]))
                    test_2 = word[pointer:pointer+temp+5]
                    if set(list(word[pointer:pointer+temp+5])).issubset(vowels): 
                        if set(list(word[pointer:pointer+temp+5])) == vowels:
                            res += 1
                        temp+=1
                    else:
                        break
                    
            pointer += 1
        return res

            