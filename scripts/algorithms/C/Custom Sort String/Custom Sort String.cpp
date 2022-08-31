// Runtime: 0 ms (Top 100.00%) | Memory: 6.5 MB (Top 11.00%)
class Solution {
public:
    string customSortString(string order, string s) {

        map<char,int>mp;

        for(int i =0 ; i<order.size() ; i++)
            mp[order[i]]=i+1;

        vector<pair<int,char> > p;
        int x=200;
        for(int i =0 ; i < s.size(); i++)
        {
            if(mp[s[i]]!=0)
            p.push_back(make_pair(mp[s[i]],s[i]));
            else
            p.push_back(make_pair(x--,s[i]));

        }

        sort(p.begin(),p.end());
        string ans="";
        for(int i =0 ;i < p.size(); i++)
        {
            ans+=p[i].second;
        }
        return ans;
    }
};