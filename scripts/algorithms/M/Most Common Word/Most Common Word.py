class Solution:
    import string
    from collections import Counter
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        #sunday morning hangover solution haha
        
        #calling this twice seems unnecesary but whatevs
        #replace "," with " " (apparently translate() is much quicker than replace)
        para = paragraph.translate(str.maketrans(","," "))
        #strip out rest of punctuation and make it lower case
        para = para.translate(str.maketrans(' ', ' ', string.punctuation)).lower()
        #split on the sapces
        para = para.split()
        #staple counter function
        para_count = Counter(para)
        #loop thru banned words, if they're in para_count pop the off
        for word in banned:
            if word in para_count:
                para_count.pop(word)
        #return val from most common
        return para_count.most_common(1)[0][0]
