class Solution {
public:
    int longestMountain(vector<int>& arr) {
     vector<int> v;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]>arr[i])v.push_back(1);
            else if(arr[i+1]<arr[i])v.push_back(-1);
            else 
                v.push_back(0);
        }
        int i=0;
        int ans=0;
        while(i<v.size())
        {
            int c1=0,c2=0;
            while(i<v.size() and v[i]==1)
            {
                c1++;
                i++;
            }
            while(i<v.size() and v[i]==-1)
            {
                c2++;
                i++;
            }
            while(i<v.size() and v[i]==0)
            {
                i++;
            }
            if(c1!=0 and c2!=0)
            {
                ans=max(ans,c1+c2+1);
            }
        }
        return ans;
    }
};
