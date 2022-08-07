class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # store len of words list (k) and len of individual words (l)
        k = len(words)
        l = len(words[0])
        
        # create a hmap (dict) of word indices for fast lookup and duplication handeling
        word_hmap = {}
        for i, word in enumerate(words):
            if word not in word_hmap:
                word_hmap[word] = [i]
            else:
                word_hmap[word] += [i]
                
        # create empty list for return
        out = []
        
        # i being the starting index 
        # no need to go over len(s)-k*l+1 since then not all words would fit
        for i in range(0, len(s)-k*l+1):
            word = s[i:i+l]
            count = 0 # to later check that we've seen each word exacly once
            j = i # index variable
            
            # keep track of indices of words that we've already seen
            seen_words_hmap = {}
            
            while word in word_hmap:
                # check that the current word is in words list, hasn't been seen before 
                # or not all duplicates of the word have been seen
                flag = False
                for idx in word_hmap[word]:
                    if not idx in seen_words_hmap:
                        seen_words_hmap[idx] = 1
                        flag = True
                        break
                if not flag:
                    break
                
                # the current word being valid, we can go to the next
                count += 1
                j += l
                word = s[j:j+l]
                
            if count == k:
                out += [i]
            
        return out  
