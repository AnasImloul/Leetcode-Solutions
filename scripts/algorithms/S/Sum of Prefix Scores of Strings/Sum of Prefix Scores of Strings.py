# Runtime: 3764 ms (Top 9.66%) | Memory: 387.60 MB (Top 26.14%)

class Node:
    def __init__(self):
        self.count = 0
        self.list = [None] * 26

    def containKey(self, ch):
        return self.list[ord(ch) - ord('a')] is not None

    def get(self, ch):
        return self.list[ord(ch) - ord('a')]

    def put(self, ch, new_node):
        self.list[ord(ch) - ord('a')] = new_node

    def inc(self, ch):
        self.list[ord(ch) - ord('a')].count += 1

    def retCount(self, ch):
        return self.list[ord(ch) - ord('a')].count


class Solution:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        node = self.root
        for ch in word:
            if not node.containKey(ch):
                node.put(ch, Node())
            node.inc(ch)
            node = node.get(ch)

    def search(self, word):
        node = self.root
        preCount = 0
        for ch in word:
            preCount += node.retCount(ch)
            node = node.get(ch)
        return preCount

    def sumPrefixScores(self, words):
        # This problem can be solved using the trie data structure
        for word in words:
            self.insert(word)

        res = []
        for word in words:
            preCount = self.search(word)
            res.append(preCount)

        return res
