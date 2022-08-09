typedef pair<int,int> pi;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<pi>serv;
        for(int i = 0; i<servers.size(); i++)serv.push_back({servers[i],i});
        int curr = 0;
        priority_queue<pi, vector<pi>, greater<pi>>mi(serv.begin(),serv.end());
        vector<int>ans;
        map<int,vector<pi>>free;
        int t = 0;
        while(1){
            for(auto s : free[t])mi.push(s);
            free.erase(t);
            while(curr<=t && curr<tasks.size() && !mi.empty()){
                auto se = mi.top();
                mi.pop();
                free[t+tasks[curr]].push_back(se);
                ans.push_back(se.second);
                curr++;
            }
            if(curr>=tasks.size())break;
            if(mi.empty()){
                auto it = free.begin();
                t = it->first;
            }
            else t++;
        }
        return ans;
    }
};
