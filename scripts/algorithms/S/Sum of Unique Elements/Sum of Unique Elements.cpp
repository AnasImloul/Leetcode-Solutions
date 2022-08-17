class Solution {
public:
    int sumOfUnique(vector<int>& nums)
    {
       int sum=0;
       map<int,int>mp;
        
       for(auto x:nums)
       mp[x]++;
        
       for(auto m:mp)
       {
           if(m.second==1)
               sum+=m.first;
       }
        return sum;
    }
};
