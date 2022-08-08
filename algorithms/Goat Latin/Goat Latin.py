class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        wordList, result, index = sentence.split(' '), "", 1
        for word in wordList:
            if index > 1:
                result += " "
            firstLetter = word[0]
            if firstLetter in 'aeiouAEIOU':
                result += word + "ma"
            else:
                result += word[1:] + firstLetter + "ma"
            for i in range(index):
                result += 'a'
            index += 1
        return result
