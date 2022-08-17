class Solution {
public:
    bool static comp(pair<string, int> a, pair<string, int> b){
        if(a.second > b.second) return true;
        else if(a.second < b.second) return false;
        else{
            return a.first < b.first;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(auto i : words){
            m[i]++;
        }
        vector<pair<string, int>> v;
        for(auto i : m){
            v.push_back(i);
        }
        sort(v.begin(), v.end(), comp);
        vector<string> ans;
        for(int i=0; i<k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
