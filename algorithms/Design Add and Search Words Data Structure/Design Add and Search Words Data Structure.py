class TrieNode:
    
    def __init__(self, val):
        self.val = val
        self.children = {}
        self.isEnd = False


class WordDictionary:

    def __init__(self):
        self.root = TrieNode("*")
        
    def addWord(self, word: str) -> None:
        
        curr = self.root
        
        for c in word:
            
            if c not in curr.children:
                curr.children[c] = TrieNode(c)
                
            curr = curr.children[c]
        
        curr.isEnd = True
        
    def search(self, word: str) -> bool:
        
        def dfs(root, word):
            curr = root

            for i in range(len(word)):

                if word[i] == ".":
                    for l in curr.children.values():
                        if dfs(l, word[i+1:]) == True:
                            return True
                        
                    return False

                if word[i] not in curr.children:
                    return False

                curr = curr.children[word[i]]

            return curr.isEnd
        
        return dfs(self.root, word)
