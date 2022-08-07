class Solution {
    public int[] findMode(TreeNode root) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        func(hm,root);
        Set<Integer> set = hm.keySet();
        ArrayList<Integer> al = new ArrayList<>(set);
        ArrayList<Integer> al1 = new ArrayList<>(hm.values());
        ArrayList<Integer> al2 = new ArrayList<>();
        int max = 0;
        for(int i = 0; i < al.size(); i++){    
            if( al1.get(i) > max){
                max  = al1.get(i);
            }
        }
        for(int i = 0; i < al.size(); i++){
            int value = al1.get(i);
            if(value == max){
                al2.add(al.get(i));
            }
        }
        int[] arr = new int[al2.size()];
        int i = 0;
        for(Integer a : Arrays.copyOf(al2.toArray(), al2.size(), Integer[].class)){
            arr[i++] = a.intValue();
        }
        
        return arr;
    }
    
    public void func( HashMap<Integer,Integer> hm , TreeNode root) //traverse by preorder
    {
       
        if(root != null){
              int value = root.val;
        
        if(hm.containsKey(value)){
            hm.put(value,1 + hm.get(value));
            
        }
        else
            hm.put(value,1);
        
        func(hm,root.left);
        func(hm,root.right);
        }
      
        
    }
}
