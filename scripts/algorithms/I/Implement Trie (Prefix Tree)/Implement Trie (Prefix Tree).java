// Runtime: 67 ms (Top 53.89%) | Memory: 70 MB (Top 22.15%)
class Trie {
    private class Node{
        char character;
        Node[] sub;
        Node(char c){
            this.character = c;
            sub = new Node[26];
        }
    }
    Node root;
    HashMap<String, Boolean> map;
    public Trie() {
        root = new Node('\0');
        map = new HashMap<>();
    }

    public void insert(String word) {
        Node temp = root;
        for(char c : word.toCharArray()){
            int index = c-'a';
            if(temp.sub[index] == null)
                temp.sub[index] = new Node(c);

            temp = temp.sub[index];
        }
        map.put(word, true);
    }

    public boolean search(String word) {
        return map.containsKey(word);
    }

    public boolean startsWith(String prefix) {
        Node temp = root;
        for(char c : prefix.toCharArray()){
            int index = c-'a';
            if(temp.sub[index] == null)
                return false;
            temp = temp.sub[index];
        }
        return true;
    }
}