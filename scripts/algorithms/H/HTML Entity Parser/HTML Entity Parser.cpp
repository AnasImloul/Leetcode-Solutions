class Solution {
public:
    string entityParser(string text) {
        map<string,char>mp;
        mp["&quot;"] = '\"';
        mp["&apos;"] = '\'';
        mp["&amp;"] = '&';
        mp["&gt;"] = '>';mp["&lt;"]='<';
        mp["&frasl;"] = '/';
        
        for(int i =0;i<text.size();i++){
            if(text[i]=='&'){
                int j = i;
                string com ="";
                while(text[j]!=';' && j<text.size()){
                    com+=text[j];
                    j++;
                }
                com+=text[j];
                if(mp.find(com)!=mp.end()){
                    text.erase(i,j-i);
                    text[i] = mp[com];
                }
                
            }
        }
        return text;
    }
};
