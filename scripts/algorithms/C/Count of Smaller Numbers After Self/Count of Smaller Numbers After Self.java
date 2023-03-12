class Solution {
    public int[] tree = new int[400000];
    
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        List<Integer> list =  new ArrayList<>();
        for(int i = 0 ; i < n ; i++)
            nums[i] = nums[i]+10000;
        
        for(int i = n-1 ; i >= 0 ; i--)
        {
            updateTree(0 , 0 , 20000 , nums[i]);
            list.add(query(0 , 0 , 20000 , 0 , nums[i]-1));
        }
        
        Collections.reverse(list);
        return list;
    }
    
    public void updateTree(int ind , int low , int high , int val){
        if(low == high){
            tree[ind]++;
            return;
        }
        
        int mid = (low+high)/2;
        if(mid >= val)
            updateTree(2*ind+1 , low , mid , val);
        else
            updateTree(2*ind+2 , mid+1 , high  , val);
        
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
    
    public int query(int ind , int low , int high , int left , int right){
        if(low >= left && high <= right){
            return tree[ind];
        }
        
        if(high < left || low > right)
            return 0;
        
        int mid = (low+high)/2;
        int leftFind = query(2*ind+1 , low , mid , left , right);
        int rightFind = query(2*ind+2 , mid+1 , high , left , right);
        
        return leftFind+rightFind;
    }
}