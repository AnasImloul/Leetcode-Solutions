class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int>v;
        stack<int>s;
        
        for(auto x: asteroids){
            
            if(x > 0) s.push(x);
            
            else{
                
                // Case 1: whem top is less than x
                
                while(s.size() > 0 && s.top() > 0 && s.top() < -x){
                    s.pop();
                }
                
                // case 2 : when both of same size
                if(  s.size() > 0 && s.top()==-x) {
                    s.pop();
                }
                
                // case 3: when top is greater
                
                else if( s.size() > 0 && s.top() > -x ){
                   // do nothing
                }
                
                // case 4: when same direction 
                
                else{
                    s.push(x);
                }
            }
        }
        
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        
        reverse(v.begin(),v.end());
        
        return v;
    }
};