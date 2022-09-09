// Runtime: 4 ms (Top 45.16%) | Memory: 8 MB (Top 87.37%)
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s="";
        if(nums.size()==1)
            return to_string(nums[0]);
        if(nums.size()==2)
            return to_string(nums[0])+'/'+to_string(nums[1]);
        for(int i=0;i<nums.size();i++)
        {
            s+=to_string(nums[i])+"/";
            if(i==0)
                s+="(";
        }
        s[s.size()-1]=')';
        return s;
    }
};