// Runtime: 36 ms (Top 16.60%) | Memory: 11.7 MB (Top 62.43%)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> v;
        unordered_map<string,int> m;
        for(auto it : cpdomains){
            string rep="";
            int i=0;
            while(it[i]!=' '){
                  rep+=(it[i]);
                    i++;
            }
            int r=stoi(rep);
            m[it.substr(i+1,it.size())]+=r;

            while(it[i]!='.'){
                i++;
            }
            m[it.substr(i+1,it.size())]+=r;
            i++;
            while(i<it.size() and it[i]!='.'){
                i++;
            }
            if(i!=it.size()){
            m[it.substr(i+1,it.size())]+=r;
            }

        }

        for(auto it : m){
            string a=it.first;
            string b=to_string(it.second);
            a=b+" "+a;
            v.push_back(a);
        }
        return v;
    }
};