class Solution {
    
    
    
    int findMax(List<Integer> al){
       int i=0;
        for(;i<al.size();i++){
            if(al.get(i)!=-1){
               break;
            }
        }
        int j=al.size()-1;
         for(;j>=0;j--){
            if(al.get(j)!=-1){
                 break;
            }
        }
        System.out.print(al +" max is "+(j-i+1)+ "for " +i+" "+j);
        return j-i+1;
    }
    
    
    
    public int widthOfBinaryTree(TreeNode root) {
        
       if(root==null) return 0; 
        Queue<TreeNode> q =new LinkedList<>();
        q.add(root);
       int max=1;     
        while(!q.isEmpty()){
            int size = q.size();
            ArrayList<Integer> al = new ArrayList<>();
            Set<Integer> hs =new HashSet<>();
            for(int i=0;i<size;i++){
               TreeNode curr =q.poll(); 
                System.out.print(curr.val);
                if(curr.left!=null && curr.left.val!=-1){
                    q.offer(curr.left);
                    hs.add(curr.left.val);
                }else if(curr.left==null){
                    q.offer(new TreeNode(-1));
                    hs.add(-1);
                }
                
                
                if(curr.right!=null && curr.right.val!=-1){
                    q.offer(curr.right);
                    hs.add(curr.right.val);
                }else if(curr.right==null){
                    q.offer(new TreeNode(-1));
                    hs.add(-1);
                }
            
                al.add(curr.val);
            }
             // System.out.println(al);
            
           max =Math.max(max,findMax(al)); 
            
            // && hs.iterator().next()==-1
           if(hs.size()==1){
               // System.out.println(max+" max");
               break;
           }  
        }
         
        
        // System.out.print(res);
        return max;
    }
}
