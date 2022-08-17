class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto a: asteroids){
            if(s.empty()) s.push(a);
            else{
                while(!s.empty() && a < 0 && s.top() * a < 0){
                    if(abs(a) == abs(s.top())){ a = 0; s.pop(); }
                    else if( abs(a) < abs(s.top()))  a = 0;
                    else s.pop();
                }
                if(a) s.push(a);
            }
        }
        vector<int> ans;
        while(!s.empty()) { ans.push_back(s.top()); s.pop(); }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
