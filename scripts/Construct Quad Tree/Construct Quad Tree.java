/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    public Node construct(int[][] grid) {
        return helper(grid,0,grid.length-1,0,grid.length-1);
    }
    Node helper(int[][] grid,int l,int r,int t,int b){
        if(l==r){
            if(grid[t][l]==1)return new Node(true,true);
            else return new Node(false,true);
        }
        if(allOnes(grid,l,r,t,b)){
            Node res=new Node(true,true);
            return res;
        }
        if(allZeros(grid,l,r,t,b)){
            Node res=new Node(false,true);
            return res;
        }
        Node tl=helper(grid,l,(l+r)/2,t,(t+b)/2);
        Node tr=helper(grid,((l+r+1)/2),r,t,(t+b)/2);
        Node bl=helper(grid,l,(l+r)/2,(t+b+1)/2,b);
        Node br=helper(grid,((l+r+1)/2),r,(t+b+1)/2,b);
        return new Node(true,false,tl,tr,bl,br);
    }
    boolean allOnes(int[][] grid,int l,int r,int t,int b){
        //System.out.println(l+" "+r+" "+t+" "+b);
        for(int i=t;i<=b;i++){
            for(int j=l;j<=r;j++){
                if(grid[i][j]!=1){return false;}
            }
            
        }
        
        return true;
    }
    boolean allZeros(int[][] grid,int l,int r,int t,int b){
        for(int i=t;i<=b;i++){
            for(int j=l;j<=r;j++){
                if(grid[i][j]!=0)return false;
            }
        }
        return true;
    }
}
