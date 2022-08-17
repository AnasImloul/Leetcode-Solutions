class Node{
    int max;
    int prefSt,prefEnd;
    int suffSt,suffEnd;
    Node(int max,int prefSt,int prefEnd,int suffSt,int suffEnd){
        this.max=max;
        this.prefSt=prefSt;
        this.prefEnd=prefEnd;
        this.suffSt=suffSt;
        this.suffEnd=suffEnd;
    }
}

class SegmentTree{
    Node [] tree;
    StringBuilder s;
    SegmentTree(String s){
        this.s=new StringBuilder();
        this.s.append(s);
        tree=new Node[4*s.length()];
        build(0,0,s.length()-1);
    }
    
    Node merge(Node left,Node right,int tl,int tm,int tr){
        int max=Integer.max(left.max,right.max);
        int prefSt=left.prefSt;
        int prefEnd=left.prefEnd;
        int suffSt=right.suffSt;
        int suffEnd=right.suffEnd;
        
        if(s.charAt(tm)==s.charAt(tm+1)){
            max=Integer.max(max,right.prefEnd-left.suffSt+1);
            if(left.prefEnd-left.prefSt+1==tm-tl+1)
                prefEnd=right.prefEnd;
            if(right.suffEnd-right.suffSt+1==tr-tm)
                suffSt=left.suffSt;
        }
        
        return new Node(max,prefSt,prefEnd,suffSt,suffEnd);
    }
    
    void build(int pos,int tl,int tr){
        if(tl==tr){
            tree[pos]=new Node(1,tl,tl,tr,tr);
        }else{
            int tm=tl+(tr-tl)/2;
            build(2*pos+1,tl,tm);
            build(2*pos+2,tm+1,tr);
            
            tree[pos]=merge(tree[2*pos+1],tree[2*pos+2],tl,tm,tr);
        }
    }
    
    void update(int pos,int tl,int tr,int idx,char ch){
        if(tl==tr){
            tree[pos]=new Node(1,tl,tl,tr,tr);
            s.setCharAt(idx,ch);
            // System.out.println(pos);
        }
        else{
            int tm=tl+(tr-tl)/2;
            if(idx<=tm)
                update(2*pos+1,tl,tm,idx,ch);
            else
                update(2*pos+2,tm+1,tr,idx,ch);
            tree[pos]=merge(tree[2*pos+1],tree[2*pos+2],tl,tm,tr);
        }
    }
}

class Solution {
    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) {
        int k=queryIndices.length;
        SegmentTree tree=new SegmentTree(s);
        for(int i=0;i<k;i++){
            tree.update(0,0,s.length()-1,queryIndices[i],queryCharacters.charAt(i));
            queryIndices[i]=tree.tree[0].max;
        }
        return queryIndices;
    }
}
