class TrieNode:
    
    def __init__(self):
        self.children = {}
        self.endOfWord = False

class StreamChecker:

    def __init__(self, words: List[str]):
        self.root = TrieNode()
        self.qCur = self.root
        self.stream = collections.deque()
        cur = self.root
        for word in words:
            for i in range(len(word) - 1, -1, -1):
                ch = word[i]
                if ch not in cur.children:
                    cur.children[ch] = TrieNode()
                cur = cur.children[ch]
            cur.endOfWord = True
            cur = self.root

    def query(self, letter: str) -> bool:
        self.stream.appendleft(letter)
        cur = self.root
        for ch in self.stream:
            if ch not in cur.children:
                return False
            else:
                cur = cur.children[ch]
                if cur.endOfWord:
                    return True
        return False
