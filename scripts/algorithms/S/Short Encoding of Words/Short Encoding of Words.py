class Solution:
    def minimumLengthEncoding(self, words):
        
        
        # root of suffix trie
        trie_root = dict()
        
        # helper function to judge leaf node
        isLeafNode = lambda node: len(node) == 0
        
        # collection of tail nodes
        tail_nodes = []
        
        # set of unique words
        unique_words = set(words)
        
        # scan each word
        for word in unique_words:
            
            # build suffix trie from root node
            cur = trie_root
            
            # scan each character in reversed order
            for char in reversed(word):
                
                # update trie
                cur[char] = cur.get(char, dict() )
                
                # go to next level
                cur = cur[char]
            
            # save tail nodes with corresponding word length, +1 is for '#' symbol
            tail_nodes.append( (cur, len(word)+1) )

        # summation of the length with all tail node which is also a leaf node
        return sum( suffix_length for node, suffix_length in tail_nodes if isLeafNode(node) )