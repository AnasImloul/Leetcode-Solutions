class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        for(auto word:words){
            int b=0;
            for(int i=0;i<pref.size();i++){
                if(word[i]!=pref[i]){
                    break;
                }else{
                    b++;
                }
            }
            if(b==pref.size()){
                c++;
            }
        }
        return c;
    }
};