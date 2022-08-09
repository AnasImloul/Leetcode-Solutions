class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int i,j,max_possible_or=0,n=nums.size(),ans=0;
        
        //maximum possible or=or of all number in array
        for(i=0;i<n;i++)
        {
            max_possible_or=nums[i]|max_possible_or;
        }
        
        //checking all subset 
        
        
        for(i=1;i<(1<<n);i++)
        {
            int p=0;
            for(j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    p=p|nums[j];
                }
            }
            //if xor of given subset is equal to maximum possible or
			
            if(p==max_possible_or)
            {
                ans++;
            }
        }
        
        return ans;
        
    }
};
