class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
    stringstream ss(s);
    string temp;
    int i=1;
        while(ss>>temp) {
            if(temp.compare(0, sw.size(),sw)==0) return i;
            i++;
        }
        return -1;
    }
};