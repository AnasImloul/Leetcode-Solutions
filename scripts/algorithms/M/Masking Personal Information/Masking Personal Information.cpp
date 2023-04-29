class Solution {
public:
  string email(string &s, int id){
    string t = string(1, s[0] | ' ') + "*****" + string(1, s[id-1] | ' ');
  
    for(int i = id + 1; i != s.size(); i++) 
      if(s[i] != '.') s[i] |= ' ';
    
    return t + s.substr(id, s.size());
  }
  
  string phone(string &s){
    string table[] = { "" , "+*-", "+**-", "+***-" }, t;
    
    for(auto &ch: s)
      if(ch >= '0' && ch <= '9') t.push_back(ch);
   
    return table[t.size() - 10] + "***-***-" + t.substr(t.size() - 4, 4);
  }
  
  string maskPII(string s) {
    int id = s.find('@'); 
    return id == -1 ? phone(s) : email(s, id);
  }
};