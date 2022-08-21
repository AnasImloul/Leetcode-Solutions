// Runtime: 109 ms (Top 13.91%) | Memory: 21.3 MB (Top 27.37%)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string t=strs[i];
            sort(t.begin(),t.end());
            mp[t].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            vector<string> flag;
            for(auto each:it.second)
            {
                flag.push_back(strs[each]);
            }
            ans.push_back(flag);
        }

        return ans;
    }
};