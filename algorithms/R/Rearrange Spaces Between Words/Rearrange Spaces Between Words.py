class Solution(object):
    def reorderSpaces(self, text):
        word_list = text.split()
        words, spaces = len(word_list), text.count(" ")
        
        if words > 1:
            q, r = spaces//(words-1), spaces%(words-1)
            return (" " * q).join(word_list) + " " * r
        else:
            return "".join(word_list) + " " * spaces
