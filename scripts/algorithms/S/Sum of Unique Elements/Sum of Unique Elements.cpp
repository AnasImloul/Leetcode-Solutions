// Runtime: 10 ms (Top 6.43%) | Memory: 8.1 MB (Top 24.14%)
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