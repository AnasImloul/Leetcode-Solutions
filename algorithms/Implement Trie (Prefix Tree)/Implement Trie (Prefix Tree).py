class Node : 
    def __init__(self ):
        self.child = {} # to hold the nodes.
        self.end = False # to mark a node if it is the end node or not.

class Trie:
    
    def __init__(self):
        self.root = Node()

    def insert(self, word:str) -> None:
        # time compl len(word)
        
        sz = len(word) 
        temp = self.root # to hold the root node.
        
        for ind , i in enumerate( word ) :
            if i in temp.child.keys() : # if this curr char in the current node.
                temp = temp.child[i] #another node.
                
            else:
                temp.child[i] = Node()
                temp = temp.child[i]

                
            if ind  == sz - 1 :
                temp.end = True 
                
                

    def search(self, word: str) -> bool:
        
        temp = self.root 
        for i in word : 
            if i in temp.child.keys():
                temp = temp.child[i]
            else:
                return 0
            
        return temp.end == True  
         
    def startsWith(self, prefix: str) -> bool:
        temp  = self.root 
        for i in prefix :
            if i in temp.child.keys():
                temp = temp.child[i]
            else:
                return 0
        return 1 


