class Solution {
public:
    int findLucky(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }

        for(auto x:mp)
        {
            if(x.first == x.second)
            {
                v.push_back(x.first);
            }
           
        }

        int mx = -1;
        for(int i=0;i<v.size();i++)
        {
            mx = max(mx,v[i]);
        }



        return mx;
        
    }
};