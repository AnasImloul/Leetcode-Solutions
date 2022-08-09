import re
class Solution:
    def countValidWords(self, sentence: str) -> int:
        
        # parse and get each word from sentence
        words = sentence.split()
        
        # regular expression pattern for valid words
        pattern = re.compile( r'^([a-z]+\-?[a-z]+[!\.,]?)$|^([a-z]*[!\.,]?)$' )
        
        # valid word count
        count = 0
        
        # scan each word from word pool
        for word in words:
            
            # judge whether current word is valid or not
            match = re.match(pattern, word)
            
            if match:
                count+=1
                
        return count
