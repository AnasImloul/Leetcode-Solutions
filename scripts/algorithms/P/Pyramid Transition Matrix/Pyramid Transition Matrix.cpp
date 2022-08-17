class Solution {
    unordered_map<string,vector<char> > m;
public:
    bool dfs(string bot,int i,string tem){
        if(bot.size()==1) return true;
        if(i==bot.size()-1) {
            string st;
            return dfs(tem,0,st);
        }
        for(auto v:m[bot.substr(i,2)]){
            tem.push_back(v);
            if(dfs(bot,i+1,tem)){
                return true;
            }
            tem.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto a:allowed){
            m[a.substr(0,2)].push_back(a[2]);
        }
        string te;
        return dfs(bottom,0,te);
    }
};
