class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans(l.size(),false);
        for(int i=0;i<l.size();i++)
        {
            //if the sub array size is equal to 2
            if(r[i]-l[i]+1==2)
                ans[i]=true;
            else if(isArthemetic(nums,l[i],r[i]))
                ans[i]=true;
        }
        return ans;
    }
    
    //return true if the sub array can be rearranged in a arthemetic sequence
    bool isArthemetic(vector<int>& nums,int start,int end)
    {
        //get the maximum and min elements 
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=start;i<=end;i++)
        {
            mini=min(nums[i],mini);
            maxi=max(nums[i],maxi);
        }
        
        //when mini==maxi it means all the elements are same in the sub array
        if(mini==maxi)
            return true; 
        
        //we cant have same common difference betweeen  two adjacent  elements
        //when we arrange in arthemetic sequence
        if((maxi-mini)%(end-start)!=0)
            return false;
        
        
        //the diff between every two integers when we rearrange sub array
        int diff=(maxi-mini)/(end-start);
        
        //to check  if the duplicate elemnts are present
        //ex- [2,4,6,6]
        //6 is repeating two times 
        vector<bool> present(end-start+1,false);
        for(int i=start;i<=end;i++)
        {
            
            //we cant set a index of nums[i]
            if((nums[i]-mini)%diff!=0)
                return false;
            
            int ind=(nums[i]-mini)/diff;
            
            // same element is alreeady repeated ( 6 in the above  example)
            if(present[ind])
                return false;
            //mark it presence
            present[ind]=true;
            
        }
        return true;
        
    }
};
