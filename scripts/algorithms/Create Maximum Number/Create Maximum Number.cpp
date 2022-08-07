class Solution {
public:
    vector<int> func(vector<int> &nums, int k)
    {
        vector<int> ret(k, 0);
        int n=nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            if(ret.empty() || ret.back()>=nums[i])
            {
                if(ret.size()<k)
                    ret.push_back(nums[i]);
            }
            else{
                while(!ret.empty() && n-i>k-ret.size() && ret.back()<nums[i])
                    ret.pop_back();
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
    bool isGreater(vector<int> &a, vector<int> &b)
    {
        for(int i=0; i<a.size(); i++)
        {
            if(b[i]>a[i])
                return false;
            else if(b[i]<a[i])
                return true;
        }
        return false;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v1, v2;
        vector<int> ret(k, 0);
        for(int i=0; i<=k; i++)
        {
            if(i>nums1.size() || k-i>nums2.size())
                continue;
            vector<int> x, y;
            if(i)
                x=func(nums1, i);
            if(k-i)
                y=func(nums2, k-i);
            vector<int> res;
            int p=0, q=0, m=x.size(), n=y.size();
            x.push_back(0);
            y.push_back(0);
            while(p<m && q<n)
            {
                if(x[p]>y[q])
                    res.push_back(x[p++]);
                else if(x[p]<y[q])
                    res.push_back(y[q++]);
                else
                {
                    bool flag=true;
                    int t=1;
                    while(p+t<m && q+t<n && x[p+t]==y[q+t])
                        t++;
                    if(p+t>=m || (q+t<n && x[p+t]<y[q+t]))
                        flag=false;
                    if(flag)
                        res.push_back(x[p++]);
                    else
                        res.push_back(y[q++]);
                }
            }
            while(p<m)
                res.push_back(x[p++]);
            while(q<n)
                res.push_back(y[q++]);
            if(isGreater(res, ret))
                ret=res;
        }
        return ret;
    }
};

