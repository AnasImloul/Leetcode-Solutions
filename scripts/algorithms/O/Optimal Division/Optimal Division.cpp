// Runtime: 0 ms (Top 100.0%) | Memory: 8.50 MB (Top 25.14%)

// This code is using 2nd Approach.

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        string ans;
		
		// check for size if its 1 then we can't use parantheses and 
		// if its 2 then also we should not use it.
		
        if(n==1) return ans=to_string(nums[0]);
        if(n==2) return ans=to_string(nums[0])+"/"+to_string(nums[1]);
		
		//  for size greater than 2 add paranthese after first number 
		
        ans=to_string(nums[0]);
        ans.append("/(");
        for(int i=1;i<n-1;i++){
            ans.append(to_string(nums[i])+"/");
        }
        ans.append(to_string(nums[n-1]));
        ans.append(")");
		
		// finally this becomes as a/(b/c/d/....) which is our answer
		
        return ans;
    }
};
