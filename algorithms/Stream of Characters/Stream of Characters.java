class StreamChecker {
    
    class TrieNode {
        boolean isWord;
        TrieNode[] next = new TrieNode[26];
    }
    
    TrieNode root = new TrieNode();
    StringBuilder sb = new StringBuilder();
    
    public StreamChecker(String[] words) {
        createTrie(words);
    }
    
    public boolean query(char letter){
        sb.append(letter);
        TrieNode node = root;
        for(int i=sb.length()-1; i>=0 && node!=null; i--){
            char ch = sb.charAt(i);
            node = node.next[ch - 'a'];
            if(node != null && node.isWord){
                return true;
            }
        }
        return false;
    }
    
   private void createTrie(String words[]){
       for(String s : words){
           TrieNode node = root;
           int len = s.length();
           for(int i = len-1; i>=0; i--){
               char ch = s.charAt(i);
               if(node.next[ch-'a'] == null){
                   node.next[ch - 'a'] = new TrieNode();
               }
               node = node.next[ch - 'a'];
           }
           node.isWord = true;
       }
   }
}
