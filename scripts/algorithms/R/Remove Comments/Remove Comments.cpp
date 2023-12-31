// Runtime: 0 ms (Top 100.0%) | Memory: 8.10 MB (Top 52.2%)

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {      
        string cur="";
        vector<string> out;
        bool comm=false; // it will help us see whether comment is active or not

        for(string s: source){
            for(int j=0; j<s.size(); j++){
                // that means a comment is started
                if(!comm && s[j]=='/' && s[j+1]=='*'){
                    comm = true;
                    j++;
                }
                // what if a // <- is present, then full line is not read & break
                // also make sure it is outside comments
                else if(!comm && s[j]=='/' && s[j+1]=='/') break;
                // check if a comment is completed
                else if(comm && s[j]=='*' && s[j+1]=='/') {
                    comm=false;
                    j++;
                }
                // or else it is a valid code
                else if (!comm)
                    cur+=s[j];
            }
            // now check if it's a comment or not and its not blank (because comments
            // are blank lines) and add it to output

            if(!comm && cur.size()){
                out.push_back(cur);
                cur="";
            }
        }
        return out; 
    }
};
