class Solution {
public:
   
    bool helper(vector<int> &res,unordered_set<int> &s,int i,int n){
        if(s.size()==0){
            return true;
        }
        if(res[i]!=-1){
            return helper(res,s,i+1,n);
        }
        for(int j = n; j >= 1; j-- ){
            int distance;
            if(j > 1){
                distance = j;
            }
            else{
                distance = 0;   // if j == 1 distance is 0 as one is to be inserted only once
            }
            if((i+distance < res.size() and res[i+distance] == -1) and s.count(j)){
                res[i] = j;
                res[i+distance] = j;
                s.erase(j);
                if(helper(res,s,i+1,n)){
                    return true;
                }
                res[i] = -1;
                res[i+distance] = -1;
                s.insert(j);
            }
        }
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        int len = 2*(n-1)+1;
        vector<int> res(len,-1);
        unordered_set<int> s;
        for(int i = 1;i <= n;i++){
            s.insert(i);
        }
        helper(res,s,0,n);
        return res;
    }
};