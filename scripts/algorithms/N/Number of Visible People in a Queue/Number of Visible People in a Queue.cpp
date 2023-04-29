class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        vector<int>ans ;
        stack<int>s ;
        int a = 0;
        for(int i = h.size()-1 ; i >= 0 ; i--){
            if(s.empty()){
                ans.push_back(a);
                s.push(h[i]);a++;
            }
            else{
                if(s.top() > h[i]){
                    ans.push_back(1);
                    s.push(h[i]);a++;
                }
                else{
                int b = 0;
                while(!s.empty() && s.top() < h[i]){
                    s.pop() ; a--;b++;
                }
                if(!s.empty())b++;
                ans.push_back(b);
                s.push(h[i]); a++;
                } 
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};