// Runtime: 517 ms (Top 77.96%) | Memory: 167.2 MB (Top 67.68%)
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> ump;
        vector<int> sol;
        for(int i=0;i<n;i++)
        {
            ump[nums[i]]++;
        }
        for(auto a: ump)
        {
            if(a.second==1 and !ump.count(a.first+1) and !ump .count(a.first-1))
                sol.push_back(a.first);
        }

        return sol;
    }
};