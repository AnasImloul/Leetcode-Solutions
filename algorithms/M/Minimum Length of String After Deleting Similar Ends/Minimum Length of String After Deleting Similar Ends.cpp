class Solution {
public:
    int minimumLength(string s) {
        deque<char> dq;
        
        for(char c : s)
            dq.push_back(c);
        
        while(!dq.empty() && dq.front() == dq.back() && dq.size()!=1){
            char front = dq.front();
            while(!dq.empty() && dq.back() == front)
                dq.pop_back();
            while(!dq.empty() && dq.front() == front)
                dq.pop_front();
        }
        
        return dq.size();
    }
};