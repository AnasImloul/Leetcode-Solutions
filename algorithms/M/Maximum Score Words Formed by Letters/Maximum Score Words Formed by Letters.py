from itertools import combinations 

class Solution:
    def createNewWord(self, wordList) : 
        ans = ''
        for word in wordList :
            ans += word 
        
        charList = [i for i in ans]
        return charList 
    
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        score_dict = {}
        ord_a = 97 
        for i in range(len(score)) : 
            score_dict[chr(ord_a + i)] = score[i]
            
        max_count, sum_list, to_remove = 0, [], []
        for word in words : 
            char_list = [i for i in word]
            max_num = 0
            for char in set(char_list) : 
                if char_list.count(char) > letters.count(char) : 
                    max_num = 0
                    to_remove.append(word)
                    break 
                else : 
                    max_num += score_dict[char]*char_list.count(char)

            if max_num > 0 :
                sum_list.append(max_num)
        
            if max_num > max_count : 
                max_count = max_num 
        
        new_word = [i for i in words if i not in to_remove]
        # print(new_word)
        for i in range(2, len(sum_list)+1) :
            comb = combinations(new_word, i)
            for c in comb : 
                combinedWord = self.createNewWord(c)
                totalNum = 0
                for char in set(combinedWord) : 
                    if combinedWord.count(char) > letters.count(char) : 
                        totalNum = 0
                        break 
                    else : 
                        totalNum += score_dict[char]*combinedWord.count(char)
                if totalNum > max_count : 
                    max_count = totalNum 
                    
        return max_count 
