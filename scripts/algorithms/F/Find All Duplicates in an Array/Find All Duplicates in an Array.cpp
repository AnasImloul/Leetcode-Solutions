// Runtime: 109 ms (Top 73.24%) | Memory: 34.7 MB (Top 28.82%)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> a;
        vector<int> arr(n+1,0);
        for(int i=0;i<nums.size();i++)
            arr[nums[i]]++;

        for(int j=0;j<=n;j++)
            if(arr[j]==2) a.push_back(j);

        return a;
    }
};