// Runtime: 43 ms (Top 50.2%) | Memory: 17.50 MB (Top 5.12%)

class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        
        # create a dictionary for morse code (You can just copy & paste it! ^.^)
        ENG_to_MORSE = {  
            'a':".-", 'b':"-...", 'c':"-.-.", 'd':"-..", 'e':".",
            'f':"..-.", 'g':"--.", 'h':"....", 'i':"..", 'j':".---",
            'k':"-.-", 'l':".-..", 'm':"--", 'n':"-.", 'o':"---",
            'p':".--.", 'q':"--.-", 'r':".-.", 's':"...", 't':"-",
            'u':"..-", 'v':"...-", 'w':".--", 'x':"-..-", 'y':"-.--", 'z':"--..",
        }
        
        cnt = {}    # dictionary for different transformations
        
        for word in words:      # loop through every word
            
            tmp = ""
            
            for c in word:      # loop through every character
                tmp += ENG_to_MORSE[c]    # convert the word to morse code
                
            if tmp not in cnt:
                cnt[tmp] = 0
            else:
                cnt[tmp] += 1

        return len(cnt)     # return how many different elements in cnt
