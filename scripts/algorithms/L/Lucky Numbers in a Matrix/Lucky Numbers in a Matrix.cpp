// Runtime: 87 ms (Top 5.05%) | Memory: 15.9 MB (Top 5.33%)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        unordered_map<int,vector<int>>m;

        for(int i=0;i<matrix.size();i++){
            vector<int>temp = matrix[i];
            for(int j=0;j<temp.size();j++){
                m[j].push_back(temp[j]);
            }
        }

        unordered_map<int,int>mp;
        for(int i=0;i<matrix.size();i++){
            vector<int>helper = matrix[i];

            sort(helper.begin(),helper.end());

            mp[helper[0]]++;
        }
        vector<int>result;
        for(auto i:m){
            vector<int>helper = i.second;
            sort(helper.begin(),helper.end());
            int a = helper[helper.size()-1];
            if(mp.find(a)!=mp.end()){
                result.push_back(a);
            }
        }
        return result;
    }
};