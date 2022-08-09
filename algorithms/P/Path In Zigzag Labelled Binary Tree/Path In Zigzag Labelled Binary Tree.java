class Solution {
    
   
    
    
    public List<Integer> pathInZigZagTree(int label) 
    {
        int level, upper, parent, i = label;
        double min, max;
        List<Integer> ans = new ArrayList<Integer> ();
        
        ans.add(i);
        
        while( i> 1)
        {
            level = (int)(Math.log(i) / Math.log(2));
            upper = level -1;
            min = Math.pow(2.0, upper);
            max = Math.pow(2.0, level) - 1;
            parent = (int)(min + max) - i/2; 
            
            ans.add(0, parent);
            i = parent;
        }
        
        return ans;
        
        
    }
}
