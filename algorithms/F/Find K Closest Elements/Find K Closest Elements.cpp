class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.first==p2.first)  //both having equal abs diff
        {
            return p1.second<p2.second;
        }
        return p1.first<p2.first;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int,int>>v;    //abs diff , ele
        
        for(int i=0;i<arr.size();i++)
        {
            v.push_back(make_pair(abs(arr[i]-x),arr[i]));
        }
        
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;   
    }
};
