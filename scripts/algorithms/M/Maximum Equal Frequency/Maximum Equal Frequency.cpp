// Runtime: 157 ms (Top 72.81%) | Memory: 44.7 MB (Top 76.75%)

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp1,mp2; //one to store the frequency of each number , and one which will store the frequency of the frequency
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c=nums[i];
            mp1[c]++;
            mp2[mp1[c]]++;
            if(i!=n-1 && mp2[mp1[c]]*mp1[c]==i+1)
            //when curernt length is equal to the total same frequency of numbers then we need one more
            //number which may be anything so doesn't matter .
            //so we just traverse till n-2 and that's it.

                ans=i+2;
            if(mp2[mp1[c]]*mp1[c]==i)
            //when current length is equal to the total same frequency of numbers plus one extra no.
            //( so here taken ==i (i+1-1)) which can be 1. same as any number present 2. different number ..
            //but doesn't matter and our condition just satisfies ... so just take the current length .

                ans=i+1;
        }
        return ans;
    }
};