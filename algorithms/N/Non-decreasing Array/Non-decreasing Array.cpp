class Solution {
public:
bool checkPossibility(vector<int>& nums) {
    if(nums.size()<=2)
        return true;
    //creating a diff array(size=n-1) to store differences bw 2 consecutive ele.
    vector<int>diff(nums.size()-1);
    int neg=0;
    
    for(int i=0;i<nums.size()-1;i++)
    {
        diff[i]=nums[i+1]-nums[i];
        diff[i]<0?neg++:0; //no of negative differences
    }
    
    if(neg>1)
        return false;

    
    for(int i=0;i<diff.size();i++)
    {
        if(diff[i]<0 and i!=diff.size()-1)
        {
            if(i==0)
                // if(diff[i+1]>=0)
                continue; //if the first diff is neg, the next is obviosly>=0 as neg<=1, and this mountain can be resolved;
                // else
                    // return false;
            
            if((nums[i-1]<=nums[i+1]) || (diff[i+1])>=abs(diff[i]))
                continue;  //the major mountain cases, lemme know below if want explaination of these
            else 
                return false;
        }
    }   
    return true;
}
