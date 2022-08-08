class Solution(object):
    def isPrefixOfWord(self, sentence, searchWord):
        """
        :type sentence: str
        :type searchWord: str
        :rtype: int
        """
        word_list = sentence.split()
        counter = 0
        for word in sentence.split():
            counter+=1
            if searchWord == word[0:len(searchWord)]:
                return counter
        return -1
