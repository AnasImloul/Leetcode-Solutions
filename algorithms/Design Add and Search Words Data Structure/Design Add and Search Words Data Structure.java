class WordDictionary {
    private class Node{
        boolean last;
        Node[] sub;
        Node(){
            last = false;
            sub = new Node[26];
        }
    }
    Node root;
    public WordDictionary() {
        root = new Node();
        
    }
    
    public void addWord(String word) {
        Node temp = root;
        for(char c : word.toCharArray()){
            int index = c-'a';
            if(temp.sub[index] == null)
                temp.sub[index] = new Node();
            temp = temp.sub[index];
        }
        temp.last = true;
    }
    
    public boolean search(String word) {
        Node temp = root;
        return dfs(temp, word, 0);
    }
    private boolean dfs(Node node, String word, int i){
        if(i == word.length())
            return node.last;  
        
        int index = word.charAt(i)-'a';
        if(word.charAt(i) == '.'){
            for(int j = 0; j < 26; j++){
                if(node.sub[j] != null)
                    if(dfs(node.sub[j], word, i+1))
                        return true;
            }
            return false;
        }
        else if(node.sub[index] == null)
            return false;
        return dfs(node.sub[index], word, i+1);
    }
}
