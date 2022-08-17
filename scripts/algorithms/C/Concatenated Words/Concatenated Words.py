class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
                
        set_words = set(words)

        def check(word, seen):
            if word == '':
                return True
            for i in range(len(word) if seen else len(word) - 1):
                if word[:i+1] in set_words:
                    if check(word[i+1:], seen | {word[:i+1]}):
                        return True
            return False

        return [word for word in words if check(word, set())]
