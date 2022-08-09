class Solution {
public:
    string smallestSubsequence(string s) {
        
        string st="";
        unordered_map< char ,int> m;
        vector< bool> vis( 26,false);
        for( int i=0;i<s.size();i++) m[s[i]]++;
        
        stack< char> t;
        
        t.push(s[0]) , m[s[0]]--;
        st+=s[0];
        vis[s[0]-'a']=true;
        
        for( int i=1;i<s.size();i++){
            
            m[ s[i]]--;
            if(!vis[ s[i]-'a']){
                while( !t.empty() &&  m[t.top()] >0 && t.top() > s[i]){
                    st.pop_back();
                    vis[ t.top()-'a']=false;
                    t.pop();
                }
                t.push(s[i]);
                vis[s[i]-'a']=true;
                st=st+s[i];
            }
        }
        return st;
    }
};
