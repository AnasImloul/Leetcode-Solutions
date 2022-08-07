class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if (st.find(end) == st.end()) return -1;
        
        queue<string> q;
        q.push(start);
        
        unordered_set<string> vis;
        vis.insert(start);
        
        int res=0;
        while (not q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                string currString = q.front(); q.pop();
                if (currString == end) return res;
                
                for (int i=0;i<currString.size();i++) {
                    string temp = currString;
                    for (auto g: string("ATGC")) {
                        temp[i] = g;
                        if (st.find(temp) != st.end() and (vis.find(temp) == vis.end())) {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};
