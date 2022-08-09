class Solution {
public:
    vector<string> check(string s){
        int n = s.size();
        vector<string> res;
        if(s[0] == '0'){
            if(n == 1)
                res.push_back(s);
            else{
                if(s[n-1] == '0')
                    return res;
                
                s.insert(1, ".");
                res.push_back(s);
            }
        }
        else{
            if(s[n-1] == '0'){
                res.push_back(s);
                return res;
            }
            
            for(int i=1; i<n; i++){
                string t = s.substr(0, i) + "." + s.substr(i, n-i);
                res.push_back(t);
            }
            res.push_back(s);
        }
        
        return res;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        vector<string> res;
        
        for(int i=2; i<n-1; i++){
            vector<string> left = check(s.substr(1, i-1));
            vector<string> right = check(s.substr(i, n-i-1));
            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    string t = "(" + left[j] + ", " + right[k] + ")";
                    res.push_back(t);
                }
            }
        }
        
        return res;
    }
};
