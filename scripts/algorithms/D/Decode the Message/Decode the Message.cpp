// Runtime: 8 ms (Top 57.83%) | Memory: 7 MB (Top 72.52%)
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector <char> alpha {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        int i=0;

        map<char,char> d;

        for(int j=0;j<26;j++){
            d[alpha[j]]='0';
        }

        for(int j=0; j<key.size(); j++){

            if(key[j]!=' ' && d[key[j]]=='0'){
                d[key[j]]=alpha[i];
                i++;
            }
            if (i==26) break;
        }
        d[' '] = ' ';

        string res="";
        for(int i=0; i<message.size(); i++){
            res += d[message[i]];
        }
        return res;
    }
};