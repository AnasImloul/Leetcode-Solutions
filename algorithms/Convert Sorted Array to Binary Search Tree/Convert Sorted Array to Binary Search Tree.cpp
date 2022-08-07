class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size(); 
        if(n==0) //if no elements are present
            return NULL;
        if(n==1) //if only one element is present
            return new TreeNode(nums[0]); //create the root node with that element
        
        int mid = n/2; //finding the position of the middle element in the array
        TreeNode* root = new TreeNode(nums[mid]); //create root node with mid element
        
        vector<int> l (nums.begin(), nums.begin()+mid); //left subarray
        vector<int> r (nums.begin()+mid+1, nums.end()); //right subarray
        
        //using recursion to form the rest of the nodes :
        
        //the left nodes of the root must be smaller than root
        root->left = sortedArrayToBST(l); 
        
        //the right nodes of the root must be greater than root
        root->right = sortedArrayToBST(r);
        
        return root;
    }
};
