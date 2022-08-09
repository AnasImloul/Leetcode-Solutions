class Solution {
    class TrieNode {
        Map<Character, TrieNode> children = new HashMap();
        boolean word = false;
        public TrieNode() {}
    }
    
    int[][] dirs = new int[][]{{0,1},{0,-1},{-1,0},{1,0}};
    
    public List<String> findWords(char[][] board, String[] words) {
        Set<String> res = new HashSet<>();
        TrieNode root = new TrieNode();
        int m = board.length;
        int n = board[0].length;
        
        for(String word : words){
            char[] cArr = word.toCharArray();
            TrieNode dummy = root;
            
            for(char c : cArr){
                if(!dummy.children.containsKey(c)){
                    dummy.children.put(c, new TrieNode());
                }
                dummy = dummy.children.get(c);
            }
            
            dummy.word = true;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char nextChar = board[i][j];
                boolean[][] visited = new boolean[m][n];
                if(root.children.containsKey(nextChar)){
                    res.addAll(dfs(board, root.children.get(nextChar), i, j, visited, ""+nextChar));
                }
            }
        }
        
        return new ArrayList<>(res);
    }
    
    Set<String> dfs(char[][] board, TrieNode root, int i, int j, boolean[][] visited, String word){
        Set<String> res = new HashSet<>();
        
        if(root.word){
            res.add(word);
            root.word = false;
        }
        
        visited[i][j] = true;
        
        for(int[] dir : dirs){
            int newI = i + dir[0];
            int newJ = j + dir[1];
            
            if(newI>=0 && newI<board.length && newJ>=0 && newJ<board[0].length && !visited[newI][newJ]){
                char nextChar = board[newI][newJ];
                if(root.children.containsKey(nextChar)){
                   
                    res.addAll(dfs(board, root.children.get(nextChar), newI, newJ, visited, word+nextChar));
                    
                }
            }
        }
        
        visited[i][j] = false;
        
        return res;
    }
}
