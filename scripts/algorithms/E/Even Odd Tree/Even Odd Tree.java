// Runtime: 9 ms (Top 96.0%) | Memory: 66.10 MB (Top 31.24%)

class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> qu = new LinkedList<>();
        qu.add(root);
        boolean even = true; // maintain check for levels
        while(qu.size()>0){
            int size = qu.size();
            int prev = (even)?0:Integer.MAX_VALUE; // start prev with 0 to check strictly increasing and Integer_MAX_VALUE to check strictly decreasing 
            while(size-->0){
            TreeNode rem = qu.remove();
                if(even){
                    if(rem.val%2==0 || rem.val<=prev){ // false if value at even level is even or not strictly increasing 
                        return false;
                    }
                }else{
                    if(rem.val%2!=0 || rem.val>=prev){// false if value at odd level is odd or not strictly decreasing
                        return false;
                    }
                }
                if(rem.left!=null){
                    qu.add(rem.left); 
                }
                if(rem.right!=null){
                    qu.add(rem.right);
                }
                prev=rem.val;   //update previous
              
            }
              even = !even; //change level
        } 
        return true;
    }
}
