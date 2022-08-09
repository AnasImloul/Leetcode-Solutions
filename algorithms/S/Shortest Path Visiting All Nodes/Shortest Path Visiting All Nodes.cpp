class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        string mask = "";
        string eq = "";
        for(int i=0; i<n; i++){
            mask += '0';
            eq += '1';
        }
        queue<pair<int,string>>q;
        set<pair<int,string>>s;
        for(int i=0; i<n; i++){
            string temp = mask;
            temp[i] = '1';
            q.push({i,temp});
            s.insert({i,temp});
        }
        int c = 0;
        int flag = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto top = q.front();
                q.pop();
                if(top.second == eq) return c;
                for(auto p: graph[top.first]){
                    string temp1 = top.second;
                    temp1[p] = '1';
                    if(s.count({p,temp1}) == 0){
                        q.push({p,temp1});
                        s.insert({p,temp1});
                    }
                }
            }
            c++;
            cout<<"c is "<<c;
        }
        return -1;
    }
};
