class Solution {
    private:
    void happy(string s, vector<char> &v, int n, vector<string> &ans){
        if(s.size() == n){
            ans.push_back(s);
            return;
        }
        for(int i=0; i<3; i++){
            if(s.back() != v[i]){
                s.push_back(v[i]);
                happy(s,v,n,ans);
                s.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<char> v = {'a', 'b', 'c'};
        vector<string> ans;
        string s = "";
        happy(s,v,n,ans);
        if(ans.size() < k){
            return "";
        }
        else{
            return ans[k-1];
        }
    }
};
