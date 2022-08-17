class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        TreeNode root = construct(nums,0,nums.length-1);
        return root;
    }
    
    private TreeNode construct(int []nums, int start, int end) {
        if(start > end)
            return null;
        if(start == end)
            return new TreeNode(nums[start]);
        
        int maxIdx = findMax(nums,start,end);
        TreeNode root = new TreeNode(nums[maxIdx]);
        
        root.left = construct(nums,start,maxIdx-1);
        root.right = construct(nums,maxIdx+1,end);
        
        return root;
    }
    
    private int findMax(int []arr, int low, int high) {
        int idx = -1, max = Integer.MIN_VALUE;
        for(int i=low;i<=high;++i) 
            if(arr[i]>max) {
                max = arr[i];
                idx = i;
            }
        return idx;
    }
}
