class Solution {
public:
string orderlyQueue(string s, int k) {
 
if(k>1){
       sort(s.begin(),s.end());
       return s;
    }
    else{
        string res=s;
        
        for(int i=0;i<s.length();i++){
            s=s.substr(1)+s.substr(0,1);
            res=min(res,s);
        }
        return res;
    }
    
    return s;
    
}
};