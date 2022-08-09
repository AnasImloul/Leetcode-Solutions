class Solution {
private:
    bool isCommon(string &s,string &t){
        int index=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==t[index]){
                if(++index==t.size()){
                    return true;
                }
            }
        }
        return false;
    }
    bool isUncommon(vector<string>&strs,int index){
        for(int i=0;i<strs.size() and strs[index].size()<=strs[i].size();i++){
            if(index!=i and isCommon(strs[i],strs[index])){
                return false;
            }
        }
        return true;
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),[](string &s,string &t){
            return s.size()>t.size();
        });
        int ans=-1;
        for(int i=0;i<strs.size();i++){
            if(isUncommon(strs,i)){
                ans=strs[i].size();
                break;
            } 
        }
        return ans;
    }
};