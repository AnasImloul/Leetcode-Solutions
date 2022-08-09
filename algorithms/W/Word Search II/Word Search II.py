class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        solution = set()
        trie = self.make_trie(words)
        visited = set()
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.dfs(i,j,board,trie,visited,"",solution)
        return solution
    
    def dfs(self,i,j,board,trie,visited,word,solution):
        if "*" in trie:
            if len(trie.keys()) == 0:
                return
            else:
                solution.add(word)
                del trie["*"]
        if (i,j) in visited:
            return
        if (i < 0 or i == len(board) or j < 0 or j == len(board[0])):
            return
        if board[i][j] not in trie:
            return
        if len(trie[board[i][j]]) == 0:
            del trie[board[i][j]]
            return
        visited.add((i,j))
        neighbours = [(i,j-1),(i-1,j),(i,j+1),(i+1,j)]
        for n_x,n_y in neighbours:
            self.dfs(n_x,n_y,board,trie[board[i][j]],visited,word+board[i][j],solution)    
        visited.remove((i,j))
        
    def make_trie(self,words):
        trie = {}
        for word in words:
            current = trie
            for char in word:
                if char not in current:
                    current[char] = {}
                current = current[char]
            current["*"] = "*"
        return trie

