// Runtime: 10 ms (Top 21.11%) | Memory: 42.4 MB (Top 35.11%)
class TrieNode{
    TrieNode[] childs;
    int frequency;
    TrieNode(){
        childs = new TrieNode[26];
        this.frequency = 1;
    }
}

class Solution {

    TrieNode root = new TrieNode();

    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) return "";
        if(strs.length == 1) return strs[0];
        for(String str : strs){
            insertIntoTrie(str.toLowerCase());
        }
        return findCommonPrefix(strs[0], strs.length);
    }

    private void insertIntoTrie(String str) {
        TrieNode ptr = root;
        for(int i=0; i<str.length(); i++){
            if(ptr.childs[str.charAt(i)-'a'] == null){
                ptr.childs[str.charAt(i)-'a'] = new TrieNode();
            } else {
                ptr.childs[str.charAt(i)-'a'].frequency++;
            }
            ptr = ptr.childs[str.charAt(i)-'a'];
        }
    }

    private String findCommonPrefix(String str, int n) {
        String ans = "";
        for(int i=0; i<str.length(); i++){
            if(root.childs[str.charAt(i) -'a'].frequency != n){
                return ans;
            }
            ans += str.charAt(i);
            root = root.childs[str.charAt(i)-'a'];
        }
        return ans;
    }
}