// Runtime: 13 ms (Top 55.08%) | Memory: 13.7 MB (Top 17.99%)
class Solution {
public:

    int startEle(vector<int>& nums, int target,int l,int r)
    {
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]<target) l=m+1;
            else if(nums[m]>target) r = m-1;
            else
            {
                if(m==0)
                    return m;
                else if(nums[m-1]==target)
                    r = m-1;
                else
                    return m;
            }
        }

        return -1;
    }

     int lastEle(vector<int>& nums, int target,int l,int r)
    {
        while(l<=r)
        {
            int m = (l+r)/2;
            if(nums[m]<target) l=m+1;
            else if(nums[m]>target) r = m-1;
            else
            {
                if(m==nums.size()-1)
                    return m;
                else if(nums[m+1]==target)
                    l = m+1;
                else
                    return m;
            }
        }

         return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> binSearch;
        int a = startEle(nums,target,0,nums.size()-1);
        if(a==-1)
        {
             binSearch.push_back(-1);
             binSearch.push_back(-1);
            return binSearch;
        }
        else
        {
            binSearch.push_back(a);
        }

        int b = lastEle(nums,target,0,nums.size()-1);
        binSearch.push_back(b);

        return binSearch;

    }
};