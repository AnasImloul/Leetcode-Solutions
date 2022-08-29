// Runtime: 9000 ms (Top 21.88%) | Memory: 36.5 MB (Top 15.63%)
from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.nodes = defaultdict(TrieNode)
        self.cnt = 0

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, val):
        cur = self.root
        for i in reversed(range(15)):
            bit = val >> i & 1
            cur.nodes[bit].cnt += 1
            cur = cur.nodes[bit]

    def count(self, val, high):
        res = 0
        cur = self.root
        for i in reversed(range(15)):
            if not cur:
                break
            bit = val >> i & 1
            cmp = high >> i & 1
            if cmp:
                res += cur.nodes[bit].cnt
                cur = cur.nodes[1^bit]
            else:
                cur = cur.nodes[bit]
        return res

class Solution:
    def countPairs(self, nums: List[int], low: int, high: int) -> int:
        trie = Trie()
        res = 0
        for num in nums:
            res += trie.count(num, high + 1) - trie.count(num, low)
            trie.insert(num)

        return res