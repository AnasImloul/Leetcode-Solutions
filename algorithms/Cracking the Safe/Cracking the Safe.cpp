class Solution {
public:
    int total;
    unordered_set<string> st;
    bool func(int i,int k,int n,string& s){
        if(i==total) return 1;
        
        for(int j=0;j<k;j++){
            s.push_back(j+'0');
            
            if(s.size()>=n){
                string a = s.substr(s.size()-n);
                if(st.find(a)==st.end()){
                    st.insert(a);
                    if(func(i+1,k,n,s)) return 1;
                    st.erase(a);
                }
            }
            else if(func(i,k,n,s)) return 1;
            
            s.pop_back();
        }
        
        return 0;
    }
    string crackSafe(int n, int k) {
        total = pow(k,n);
        string s;
        func(0,k,n,s);
        return s;
    }
};

