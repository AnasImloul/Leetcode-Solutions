// Runtime: 131 ms (Top 69.64%) | Memory: 68.8 MB (Top 64.29%)

class Solution {
    public int countPairs(int[] nums, int low, int high) {
        Trie trie=new Trie();
        int cnt=0;
        for(int i=nums.length-1;i>=0;i--){
            // count all the element whose xor is less the low
            int cnt1=trie.maxXor(nums[i],low);
            // count all the element whose xor is less the high+1
            int cnt2=trie.maxXor(nums[i],high+1);
            trie.add(nums[i]);
            cnt+=cnt2-cnt1;
        }
        return cnt;
    }
}
class Trie{
    private Node root;
    Trie(){
        root=new Node();
    }
    public void add(int x){
        Node cur=root;
        for(int i=31;i>=0;i--){
            int bit=(x>>i)&1;
            if(!cur.contains(bit)){
                cur.put(bit);
            }
            cur.inc(bit);
            cur=cur.get(bit);
        }
    }
    public int maxXor(int x,int limit){
        int low_cnt=0;
        Node cur=root;
        for(int i=31;i>=0 && cur!=null;i--){
            int bit=(x>>i)&(1);
            int req=(limit>>i)&1;
            if(req==1){
                if(cur.contains(bit)){
                    low_cnt+=cur.get(bit).cnt;
                }
                cur=cur.get(1-bit);
            }else{
                cur=cur.get(bit);
            }

        }
        return low_cnt;

    }
}
class Node{
    private Node links[];
    int cnt;
    Node(){
        links=new Node[2];
        cnt=0;
    }
    public void put(int bit){
        links[bit]=new Node();
    }
    public Node get(int bit){
        return links[bit];
    }
    public boolean contains(int bit){
        return links[bit]!=null;
    }
    public void inc(int bit){
        links[bit].cnt++;
    }
}