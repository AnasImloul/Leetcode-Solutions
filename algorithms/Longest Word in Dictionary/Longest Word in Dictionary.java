class Solution {
    private class Node{
        Node[] sub;
        Node(){
            sub = new Node[26];
        }
    }
    Node root;
    StringBuilder ans;
    private void buildTire(String word){
        Node temp = root;
        int n = word.length();
        for(int i = 0; i < n-1; i++){
            int index = word.charAt(i)-'a';
            if(temp.sub[index] == null) return;
            temp = temp.sub[index];
        }
        int index = word.charAt(n-1)-'a';
        temp.sub[index] = new Node();
        
        if(word.length() > ans.length())
            ans = new StringBuilder(word);
    }
    public String longestWord(String[] words) {
        this.ans = new StringBuilder();
        this.root = new Node();
        PriorityQueue<String> pq = new PriorityQueue<>();
        pq.addAll(Arrays.asList(words));
        while(!pq.isEmpty()) buildTire(pq.poll());
        return ans.toString();
    }
}
