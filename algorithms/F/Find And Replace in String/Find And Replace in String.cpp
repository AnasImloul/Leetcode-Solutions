class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {     
        int baggage = 0;
        int n = indices.size();
        map<int, pair<string,string>> mp;
        for(int i=0;i<n;++i)
        {
            mp[indices[i]]={sources[i], targets[i]};
        }
        for(auto it:mp)
        {
            string temp = s.substr(it.first+baggage, it.second.first.size());
            if(temp ==  it.second.first)
            {
                s.erase(it.first+baggage,it.second.first.size());
                s.insert(it.first+baggage, it.second.second);
                baggage += it.second.second.size() - it.second.first.size();
            }
        }
        return s;
    }
};
