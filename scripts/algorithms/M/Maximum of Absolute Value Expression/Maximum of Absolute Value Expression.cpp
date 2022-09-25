// Runtime: 125 ms (Top 8.84%) | Memory: 29.3 MB (Top 14.63%)
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int res=0;
        int n = arr1.size();
        vector<int>v1;
        vector<int>v2;
        vector<int>v3;
        vector<int>v4;
        for(int i=0;i<n;i++)
        {
            v1.push_back(i+arr1[i]+arr2[i]);
            v2.push_back(i+arr1[i]-arr2[i]);
            v3.push_back(i-arr1[i]+arr2[i]);
            v4.push_back(i-arr1[i]-arr2[i]);
        }
        res = max(res,*max_element(v1.begin(),v1.end())-*min_element(v1.begin(),v1.end()));
        res = max(res,*max_element(v2.begin(),v2.end())-*min_element(v2.begin(),v2.end()));
        res = max(res,*max_element(v3.begin(),v3.end())-*min_element(v3.begin(),v3.end()));
        res = max(res,*max_element(v4.begin(),v4.end())-*min_element(v4.begin(),v4.end()));
        return res;
    }
};
