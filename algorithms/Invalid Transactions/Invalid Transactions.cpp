class Solution {
public:
    /*
      this  question is absolutely frustrating 🙂
    */
    
    /*
        method to split string
    */
    vector<string> split(string s){
      string t="";
        vector<string> v;
        for(int i=0;i<s.length();i++){
            if(s[i]==','){
                v.push_back(t);
                t="";
            }else{
            t+=s[i];    
            }
            
        }
        v.emplace_back(t);
        return v;
    }
    
    /*
        this function checks the second condition.
    */
    bool check(string s,string time,string city,map<string,vector<string>>mp){
        for(auto x:mp[s]){
                     vector<string>out=split(x);
                     int val1=stoi(out[1]);
                     int val2=stoi(time);
                     if(out[3]!=city and abs(val2-val1)<=60){
                        return true;
                     }
                 }
        return false;
    }
    
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;/* stores the result */
      
        map<string,vector<string>>mp;/* to search for only that person*/
        
        int n=transactions.size();
        
        vector<vector<string>>v(n,vector<string>(4));/*ith v stores info about ith transaction*/
        int c=0;
        
        for(auto x:transactions){
            vector<string> out=split(x);
            v[c]=out;
            mp[out[0]].emplace_back(x);
            c+=1;
        }
        
        for(int i=0;i<n;i++){
            
             if(stoi(v[i][2])>1000){
                 /*
                    check for first condition
                 */
                 res.emplace_back(transactions[i]);
             }else{
                 /*
                    checks for second condition.
                 */
                 if(check(v[i][0],v[i][1],v[i][3],mp)){
                     res.emplace_back(transactions[i]);
                 }
             }
            
        }
     
        return res;
    }
};
