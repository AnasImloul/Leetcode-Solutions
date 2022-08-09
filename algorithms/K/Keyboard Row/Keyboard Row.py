class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        first_row = "qwertyuiopQWERTYUIOP"
        second_row = "asdfghjklASDFGHIJKL"
        third_row = "zxcvbnmZXCVBNM"
        first_list = []
        second_list = []
        third_list = []
        one_line_words = []

        for word in words:
            if set(word).issubset(first_row):
                one_line_words.append(word)
            if set(word).issubset(second_row):
                one_line_words.append(word)
            if set(word).issubset(third_row):
                one_line_words.append(word)

        return one_line_words