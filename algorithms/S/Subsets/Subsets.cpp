class Solution {
   void subsetGenerator (vector<int> nums, int n, vector<vector<int>> &ans, int i, vector<int> subset)
   {
                                                  
        if(i>=n)    //Base Case
		{        
            ans.push_back(subset);  //the subset obatined is pushed into ans
            return ;
        }
        //including the element at index i and then calling the recursive function
         subset.push_back(nums[i]);
         solve(nums,n,ans,i+1,subset);
        
		
         //excluding the element at index i and then calling the recursive function
         subset.pop_back();
         solve(nums,n,ans,i+1,subset);
              
    }
public:

    vector<vector<int>> subsets(vector<int>& nums) {
	    int i=0;                  // index is initialized to 0 as we start from the first element
        int n=nums.size();        // size of the vector nums
		vector<int> subset;       // this vector will store each subset which is generated
        vector<vector<int>> ans;  // will store all the subsets generated
        
        subsetGenerator(nums, n, ans, i, subset);
	
        return ans;
    }
};
