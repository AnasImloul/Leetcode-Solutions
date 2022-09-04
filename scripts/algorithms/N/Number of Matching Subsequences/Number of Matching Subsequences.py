# Runtime: 851 ms (Top 55.45%) | Memory: 16.4 MB (Top 32.26%)
class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        word_dict = defaultdict(list)
        numMatch = 0
        # add words into bucket with key as order of the first letter
        for w in words:
            word_dict[ord(w[0])-ord('a')].append(w)
        # loop through the characters in s
        for c in s:
            qualified = word_dict[ord(c)-ord('a')]
            word_dict[ord(c)-ord('a')] = []
            for q in qualified:
                # if the word starts with the specified letter. i.e this is the last letter of the word
                if len(q) == 1:
                    numMatch += 1
                else:
                    word_dict[ord(q[1])-ord('a')].append(q[1:])
        return numMatch
