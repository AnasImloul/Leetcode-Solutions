// Runtime: 94 ms (Top 5.29%) | Memory: 74.9 MB (Top 5.05%)
class Solution {

    private final TrieNode trie = new TrieNode(' ');

    class TrieNode{

        private Character digit;
        private String value;
        private boolean isWord;
        private Map<Character, TrieNode> children;

        TrieNode(Character c){
            this.digit = c;
            this.isWord = false;
            this.children = new HashMap<>();
        }

        void insert(String s){
            TrieNode current = this;
            for(Character c : s.toCharArray()){
                current = current.children.computeIfAbsent(c, k -> new TrieNode(c));
            }
            current.value = s;
            current.isWord = true;
        }

        List<Integer> getWordsPreOrder(){
            return getWordsPreOrder(this);
        }

        private List<Integer> getWordsPreOrder(TrieNode root){
            List<Integer> result = new ArrayList<>();
            if(root == null){
                return result;
            }

            if(root.isWord){
                result.add(Integer.parseInt(root.value));
            }
            for(TrieNode node : root.children.values()){
                result.addAll(getWordsPreOrder(node));
            }
            return result;
        }
    }

    public List<Integer> lexicalOrder(int n) {
        for(int i = 1 ; i<=n;i++){
            trie.insert(String.valueOf(i));
        }
        return trie.getWordsPreOrder();
    }
}