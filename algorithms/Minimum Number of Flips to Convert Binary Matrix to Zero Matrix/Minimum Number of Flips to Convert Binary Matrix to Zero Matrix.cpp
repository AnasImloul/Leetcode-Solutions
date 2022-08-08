class Solution {
public:
    bool check(string str) {
        for(auto &i: str)
            if(i=='1')
                return false;
        return true;
    }
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        string str = "";
        for(auto &i: mat) {
            for(auto &j: i)
                str+=(j+'0');
        }
        
        unordered_set<string> st;
        queue<pair<string,int>> q;
        q.push({str,0});
        int steps = 0;
        
        while(q.size()) {
            string top = q.front().first;
            int step = q.front().second;
            if(check(top)) {
                    return step;
            }
            
            q.pop();
            steps++;
            for(int i=0; i<top.size(); ++i) {
                string temp = top;
                int x = i/n;
                int y = i%n;
                
                
                temp[i] = !(temp[i] - '0') + '0';
                if(x+1<m)
                    temp[y + (x+1)*n] = !(temp[y + (x+1)*n] - '0') + '0';
                if(x-1>=0)
                    temp[y + (x-1)*n] = !(temp[y + (x-1)*n] - '0') + '0';
                if(y+1<n)
                    temp[(y+1) + (x)*n] = !(temp[(y+1) + (x)*n] - '0') + '0';
                if(y-1>=0)
                    temp[(y-1) + (x)*n] = !(temp[(y-1) + (x)*n] - '0') + '0';
                
                // cout<<i<<" : "<<temp<<" "<<step+1<<endl;
                if(st.count(temp)==0) {
                    q.push({temp,step+1});
                    st.insert(temp);
                }
                
                
                if(check(temp)) {
                    return step+1;
                }
                
            }
            
        }
        return -1;
        
    }
};
