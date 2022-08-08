# a TrieNode class for creating new node
class TrieNode():
    def __init__(self):
        self.children = {}
        self.main = False
        
# the main class
class Solution(object):
    def removeSubfolders(self, folder):     
        node = TrieNode()
        res = []
        # sort the list to prevent adding the subfolder to the Trie first
        folder.sort()
        for dir in folder:
            name = dir.split("/")
            if self.addTrie(name,node):
                res.append(dir)
        return res

    # usign the same addTrie template and modify the else part
    def addTrie(self,name,node):    
        trie = node
        for c in name:
            if c not in trie.children:
                trie.children[c] = TrieNode()
            # if char is in trie,
            else:
                # check if it's the last sub folder. 
                if trie.children[c].main == True:
                    return False
            trie = trie.children[c]
        trie.main = True
        return True
